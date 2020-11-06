import math
import numpy as np
from cereal import car, log
from common.numpy_fast import clip, interp

from selfdrive.car.hyundai.spdcontroller  import SpdController

import common.log as trace1


class Spdctrl(SpdController):
    def __init__(self, CP=None):
        super().__init__( CP )
        self.cv_Raio = 0.6
        self.cv_Dist = -5
        self.steer_mode = ""
        self.cruise_gap = 0.0

    def update_lead(self, sm, CS, dRel, yRel, vRel):
        plan = sm['plan']
        dRele = plan.ddRel #EON Lead
        yRele = plan.yyRel #EON Lead
        vRele = plan.vvRel #EON Lead
        lead_set_speed = int(round(self.cruise_set_speed_kph))
        lead_wait_cmd = 600

        dRel = 150
        vRel = 0
        #dRel, yRel, vRel = self.get_lead( sm, CS )
        if 1 < dRele < 150:
            dRel = dRele # dRele(이온 차간간격)값 사용
            vRel = vRele
        elif 1 < CS.lead_distance < 150:
            dRel = CS.lead_distance # CS.lead_distance(레이더 차간간격)값 사용
            vRel = CS.lead_objspd


        dst_lead_distance = (CS.clu_Vanz*self.cv_Raio)   # 기준 유지 거리
        
        if dst_lead_distance > 100:
            dst_lead_distance = 100
        elif dst_lead_distance < 30:
            dst_lead_distance = 30

        if dRel < 150: #앞차와의 간격이 150미터 미만이면, 즉 앞차가 인식되면,
            self.time_no_lean = 0
            d_delta = dRel - float(dst_lead_distance)  # d_delta = 앞차간격(이온값) - 유지거리
            lead_objspd = vRel  # 선행차량 상대속도.
        else:
            d_delta = 0
            lead_objspd = 0
 
        if CS.driverAcc_time: #운전자가 가속페달 밟으면 크루즈 설정속도를 현재속도+5으로 동기화
            lead_set_speed = int(round(CS.clu_Vanz)) + 5
            self.seq_step_debug = "운전자가속"
            lead_wait_cmd = 15
        elif (CS.VSetDis >= 70 and lead_objspd < -30) or (lead_objspd < -40):
            self.seq_step_debug = "감속중#1"
            lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, -8)  
        elif (CS.VSetDis >= 60 and lead_objspd < -25) or (lead_objspd < -35):
            self.seq_step_debug = "감속중#2"
            lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, -6)  
        elif (CS.VSetDis >= 60 and lead_objspd < -20) or (lead_objspd < -25):
            self.seq_step_debug = "감속중#3"
            lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, -5)  
        elif (CS.VSetDis >= 50 and lead_objspd < -15) or (lead_objspd < -20):
            self.seq_step_debug = "감속중#4"
            lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, -4)
        # 거리 유지 조건
        elif d_delta < 0: # 기준유지거리(현재속도*0.6, 최소 30m이내)보다 가까이 있게 된 상황 
            self.seq_step_debug = "앞차가까움"
            if lead_objspd == 0:    # 속도 유지 시점 결정.
                if CS.VSetDis > (CS.clu_Vanz + 30):
                    self.seq_step_debug = "속도유지"
                    lead_wait_cmd = 15
                    lead_set_speed = CS.VSetDis # - 1  # CS.clu_Vanz + 5
                    if lead_set_speed < 40:
                        lead_set_speed = 40
                else:
                    self.seq_step_debug = "가속중#0"
                    #lead_set_speed = int(CS.VSetDis)
                    lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, 5)
            if lead_objspd < -30 or (dRel < 60 and CS.clu_Vanz > 60 and lead_objspd < -5): # 끼어든 차가 급감속 하는 경우
                self.seq_step_debug = "기준내,15-3"
                lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, -3)
            elif lead_objspd < -20 or (dRel < 80 and CS.clu_Vanz > 80 and lead_objspd < -5):  # 끼어든 차가 급감속 하는 경우
                self.seq_step_debug = "기준내,15-2"
                lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, -2)
            elif lead_objspd < -10:
                self.seq_step_debug = "기준내,30-1"
                lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 30, -1)
            elif lead_objspd < 0:
                self.seq_step_debug = "기준내,50-1"
                lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 50, -1)
            else:
                self.seq_step_debug = "기준내 가속"
                lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 50, 1)
        
        # 선행차량이 멀리 있으면.
        elif lead_objspd < -20 and dRel < 50:  #거리 조건 추가
            self.seq_step_debug = "감속중#5"
            lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, -2)
        elif lead_objspd < -10 and dRel < 30:  #거리 조건 추가:
            self.seq_step_debug = "감속중#6"
            lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 30, -1)
        elif lead_objspd < -7:
            self.seq_step_debug = "감속중#7"
            lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 50, -1)
        elif self.cruise_set_speed_kph > CS.clu_Vanz:
            self.seq_step_debug = ""
            # 선행 차량이 가속하고 있으면.
            if dRel >= 150: # 감지범위 밖에 멀리 떨어져 있으면
                if CS.clu_Vanz >= 60: 
                   self.seq_step_debug = "가속중#1"
                   lead_wait_cmd, lead_set_speed = self.get_tm_speed( CS, 15, 3)
                else:
                   self.seq_step_debug = "가속중#2"
                   lead_wait_cmd, lead_set_speed = self.get_tm_speed( CS, 15, 2)
            elif lead_objspd < self.cv_Dist:
                self.seq_step_debug = "가속중#3"
                lead_set_speed = int(CS.VSetDis)
            elif lead_objspd < 5:
                self.seq_step_debug = "가속중#4"
                lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, 2)
            elif lead_objspd < 10:
                self.seq_step_debug = "가속중#5"
                lead_wait_cmd, lead_set_speed = self.get_tm_speed(CS, 15, 3)
            elif lead_objspd < 20:
                if CS.clu_Vanz >= 60: 
                    self.seq_step_debug = "가속중#6"
                    lead_wait_cmd, lead_set_speed = self.get_tm_speed( CS, 15, 5)
                else:
                    self.seq_step_debug = "가속중#7"
                    lead_wait_cmd, lead_set_speed = self.get_tm_speed( CS, 15, 3)
            else:
                if CS.clu_Vanz >= 70: 
                    self.seq_step_debug = "가속중#8"
                    lead_wait_cmd, lead_set_speed = self.get_tm_speed( CS, 15, 5)
                else:
                    self.seq_step_debug = "가속중#9"
                    lead_wait_cmd, lead_set_speed = self.get_tm_speed( CS, 15, 3)

            if lead_objspd > 0 and dRel > (CS.clu_Vanz + lead_objspd) * self.cv_Raio :   # 선행차 속도를 감안한(가감속) "내차 주행 속도" 수치의 비율(cv_Raio) 보다 선행차가 멀리 있다면 가속할 수 있도록 최대 설정 속도로 설정
                self.seq_step_debug = "최대가속"
                lead_set_speed = self.cruise_set_speed_kph

        return lead_wait_cmd, lead_set_speed

    def update_curv(self, CS, sm, model_speed):
        wait_time_cmd = 0
        set_speed = self.cruise_set_speed_kph

        # 2. 커브 감속.
        #if self.cruise_set_speed_kph >= 100:
        if CS.out.cruiseState.modeSel == 1:
            if model_speed < 60 and CS.clu_Vanz > 40:
                set_speed = self.cruise_set_speed_kph - int(CS.clu_Vanz * 0.2)
                self.seq_step_debug = "커브감속-4"
                wait_time_cmd = 100
            elif model_speed < 70 and CS.clu_Vanz > 40:
                set_speed = self.cruise_set_speed_kph - int(CS.clu_Vanz * 0.15)
                self.seq_step_debug = "커브감속-3"
                wait_time_cmd = 100
            elif model_speed < 80 and CS.clu_Vanz > 40:
                set_speed = self.cruise_set_speed_kph - int(CS.clu_Vanz * 0.1)
                self.seq_step_debug = "커브감속-2"
                wait_time_cmd = 100
            elif model_speed < 90 and CS.clu_Vanz > 40:
                set_speed = self.cruise_set_speed_kph - int(CS.clu_Vanz * 0.05)
                self.seq_step_debug = "커브감속-1"
                wait_time_cmd = 100

        return wait_time_cmd, set_speed


    def update_log(self, CS, set_speed, target_set_speed, long_wait_cmd ):
        if CS.out.cruiseState.modeSel == 0:
            self.steer_mode = "오파모드"
        elif CS.out.cruiseState.modeSel == 1:
            self.steer_mode = "차간+커브"
        elif CS.out.cruiseState.modeSel == 2:
            self.steer_mode = "차간ONLY"
        elif CS.out.cruiseState.modeSel == 3:
            self.steer_mode = "편도1차선"

        if self.cruise_gap != CS.cruiseGapSet:
            self.cruise_gap = CS.cruiseGapSet

        str3 = '주행모드={:s}  설정속도={:03.0f}/{:03.0f}  타이머={:03.0f}/{:03.0f}'.format( self.steer_mode, set_speed, CS.VSetDis, long_wait_cmd, self.long_curv_timer )
        str4 = '  레이더=D:{:03.0f}/V:{:03.0f}  CG={:1.0f}  구분={:s}'.format(  CS.lead_distance, CS.lead_objspd, self.cruise_gap, self.seq_step_debug )

        str5 = str3 + str4
        trace1.printf2( str5 )

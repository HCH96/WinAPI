#pragma once

#define SINGLE(type) public:\
							static type* GetInst()\
								{\
									static type mgr;\
									return &mgr;\
								}\
					private:\
							type();\
							~type();

#define fDT CTimeMgr::GetInst()->GetDT()
#define DT CTimeMgr::GetInst()->GetfDT()
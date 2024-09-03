#ifndef _IA_ARMMOVEMENT_H_
#define _IA_ARMMOVEMENT_H_

#include "../Arm/Arm.h"
#include "../Gripper/CGripper.h"
#include "../Arm/ArmDevice.h"
#include "IA_ObjDef.h"
////////////////////////////////
typedef enum{
	eGet_Image = 0,
	ePut_In_Washer1 /*= 0*/,
	eInsert_Bolt,
	ePut_In_Nut,
	ePut_In_Washer2,
	eFasten_Nut,
	eClassify_Nut,
	eClassify_Washer,
	eClassify_Bolt,
	eLeavedObject,
	eMission_End
}teArmMissionType;
///////////////////////////////
typedef enum{
	eArm_Stop = 0,
	eArm_MoveToTargetUpside,
	eArm_GetDegree,
	eArm_PutDegree,
	eArm_OriginDegree,
	eArm_DownPtP,
	eArm_DownLine,
	eArm_CatchLoosen, 
	eArm_CatchUpPtP,
	eArm_UpLine,
	eArm_Fasten,
    eArm_MoveX,
	eArm_MoveY,
	eArm_MoveZ,
	eArm_MoveDown,
	eArm_MoveBack
}teArmMotionCmd;
///////////////////////////////

typedef enum{ Rel = 0, Abs }	teRA;
typedef enum{ PtP = 0, Line}	tePL;

// class CIA_Vector
// {
// public:
// 
// 	CVector(const CVector3D &Pos);
// 	CVector(const double &xValue , const double &yValue, const double &zValue);
// 	~CVector(void);
// };
// 
// typedef struct
// {
// 	double Pitch, Roll, Yaw;
// 	double Rot;
// 	int Singular;
// 
// }tsIA_EulerAngle;
////////////////////////////////////////////////////////////////////////////////////
class CIA_ArmInfo
{
private:
	int MotionStep;
	teArmMotionCmd* MotionSerialKey;
	//teArmMissionType CurrentMissionType;
	static CArm* IA_Arm;
	static CGripper* IA_Gripper;
	static CArmDevice* IA_ArmDevice;
	CVector3D CameraCoordinate_R;
	CVector3D CameraCoordinate_L;
	tsEulerAngle CameraEular;
	bool CameraCoordinate2nd_Flag;   //攝影機位置 True->L  False->R   
	bool Img2ndAreaCheck_Flag;       //判斷是否已到第二區(True->已到第二區)
	bool Limited_Flag;               //判斷物件是否在手臂極限外(True->物件在極限外)

	CVector3D	 TargetGoal;
	tsEulerAngle TargetEular;

	bool ImageFlag;
	int ImgObjTotalNum;
	ScrewParam* ImageObjectInfo;

	int ImgEdgeX_Left,ImgEdgeX_Right,ImgEdgeY_Front,ImgEdgeY_Back;
	int ImgPixelX,ImgPixelY;
	tsWeightMap** ImageMap;
	bool** ProhibitedAreaMap;

	bool Move_Flag;
	bool Catch_Flag;			
	bool LinePtp_Flag;		// True:目的地在目標上方	False:目的地不在目標上方

	double Height_of_Obj;
	double Height_of_Box;

	double ImgCenterArmCoordinate_R[2];
	double ImgCenterArmCoordinate_L[2];
	double MappingScaleX;
	double MappingScaleY;

	double ArmX_ErrorValue;
	double ArmY_ErrorValue;
	double ArmX_ErrorBase;
	double ArmY_ErrorBase;

	int TakeImgTimes;
	int TakeImgTotalTimes;
	vector<CObject> vObject;
	vector<CObject> vNut;
	vector<CObject> vBolt;
	vector<CObject> vWasher;
	vector<CObject> vTotalSortObj;

	bool IsTouch_Flag;
	int Vector_Size;
	double obs_x,obs_y,obsa_x,obsa_y,obj_x,obj_y;
	double end_point_roll;
	double obs_gripper1_x ,obs_gripper1_y;
	double obs_gripper2_x,obs_gripper2_y;
	double obs_gripper3_x,obs_gripper3_y;
	double obs_gripper4_x,obs_gripper4_y;
	double obs_gripper5_x,obs_gripper5_y;
	double obs_gripper6_x,obs_gripper6_y;
	double obs_gripper7_x,obs_gripper7_y;
	double obs_gripper8_x,obs_gripper8_y;

public:
	// test
	CObject* Objects;
	CBox* Boxes;

	CIA_ArmInfo();
	void IA_Initialize();
	void Get_Objects(CObject* Objptr);
	void IA_Set_Device(CArm* ArmPtr,CGripper* GripperPtr/*,CArmDevice* ArmDevicePtr*/);
	bool CheckArmCatch();
	inline bool eArm_IsBusy()		{ return IA_Arm->IsBusy(); }     //大括號內自行輸入
	inline bool eGripper_IsBusy()	{ return IA_Gripper->ISBusy(); } //大括號內自行輸入
	inline CVector3D Get_ArmPos()	{ return IA_Arm->Get_EndPos(); } //
	inline tsEulerAngle Get_ArmEularDegree();//
	void ArmStop()		{ IA_Arm->StopAll(); }
	void ArmMove(tePL PtP_Line,teRA Rel_Abs,CVector3D Goal,tsEulerAngle Eular,double Speed);
	void GripperCatch(CGripper::eCmd Catch_Mode) { IA_Gripper->Set_GripperCommand(Catch_Mode); }
	//teArmMotionCmd* IA_MissionItem(teArmMissionType* ItemNo);
	void IA_MotionItem(teArmMotionCmd* ItemNo);
	teArmMissionType* Get_MissionType();
	//void Mission_Trigger();
	//void GetInfo_Mission();
	//void GetKey_Mission();
	//void Execute_Mission();
	//void ArmMoveTo_CameraCoordinate();
	teArmMissionType CurrentMissionType;
	teArmMissionType Mission_Type;
	void Initial_ImgObjMapInfo();
	void Initial_ProhibitedAreaMap();
	void Get_Info();
	teArmMissionType Get_Mission();
	void ImgTest_Mode();
	void Mission_Excute();
	void Task_Flow();
	void Set_ImgVarInfo(bool Variable_Flag,int Variable_TotalNum,ScrewParam* Variable_ObjectInfo);
	void Set_ImageMapStack();
	void ImageInfoStack(int TotalObjNum,ScrewParam* ImgObjInfoPtr);
	void Set_vObjectType();
	void Set_vObject(int ObjX, int ObjY, tsWeightMap** Imgweightmap);
	void Set_vObjectAngle();
	double Set_BoltAngle(int BoltX, int BoltY, vector<double> vBoltAngle);
	void Set_vObjectSequence();
	ScrewParam CorrectImgObjCoordinate(ScrewParam ImgObj);
	double* MappingImgToArm(int ImgX,int ImgY);
	//void ObjToArm_Rotation(vector<CObject>* vobj);
	double ObjToArm_Rotation(CObject* obj);
	void ArmMoveTo_CameraCoordinate(int tag);
	void Arm_MoveToTargetUpside_Washer();
	void Arm_MoveToTargetUpside_Nut();
	void Arm_MoveToTargetUpside_Bolt();
	void Arm_MoveToTargetUpside_ClassifyWasherNut();
	//void Arm_MoveToTargetUpside();
	void Arm_GetDegree(teSelectObjType objtype);
	void Arm_DownPtP(/*teSelectObjType objtype*/);
	void Arm_DownLine();
	void Arm_Loosen();
	void Arm_Catch();
	void Arm_BackHome();
	void Arm_CatchUpPtP();
	void Arm_CatchUpPtP_Washer();
	void Arm_UpLine();
	void Arm_DownLine_Hole_Box_Washer();
	void Arm_DownLine_Hole_Box_Bolt();
	void Arm_MoveDown();
	void Arm_MoveBack();
	void Arm_InsertBolt_EularDeg();
	void Arm_InsertBolt_TurnPos();
	void Arm_Fasten();
	void Arm_Fasten_Back();
	void Arm_OriginDegree();
	void Arm_Stop();
	void Classify_Bolt();
	void Classify_Nut();
	void Classify_Washer();
	void Put_In_Nut();
	void Arm_DownPtP_Assorting_Box();
	void Arm_DownPtP_Hole_Box();
	void Arm_DownLine_Pole_Box();
	void Arm_DownLine_Bolt_Box();
	void Arm_Up_PtoP();
	void Arm_Put_Bolt();
	void Calibrate_Up_Little();
	void Calibrate_Roll90();
	void Calibrate_Width1();
	float degree_to_pi(float degree);
/*	void Obstacle(teSelectObjType objtype);*/
	void LimitedArea(double Tar_x, double Tar_y);

	void Obstacle();
	void Obstacle1();
	void Obstacle2();


	void DownLineClassify();


	//bool GetInfo_Flag;
	//bool GetKey_Flag;
	//bool Execute_Flag;
	//bool End_Flag;
	teArmMissionType* Set_TargetObject_GoalEular();

	bool ImgTest_Flag;               //影像測試模式
	int TaskFlow_Step;
	int GetMissionStep;
	int motion;
	int cnt;
	int i;
	int j;
	int w;
	int delay_cnt;
	double MoveZ;
	double XValue;
	double YValue;
	double ZValue;
	double Height_of_Classify;
	double Height_of_Hole_Box;
	double Height_of_Pole_Box;
	double Height_of_Fasten;
	double Height_of_Catch;
	double Height_of_Camera;
	double SpeedValue;

	double AssortingBolt_Box_X;
	double AssortingBolt_Box_Y;
	double AssortingNutWasher_Box_X;
	double AssortingNutWasher_Box_Y;
	double Hole_Box_X;
	double Hole_Box_Y;
	double Pole_Box_X;
	double Pole_Box_Y;
	double Bolt_Box_X;
	double Bolt_Box_Y;

};
#endif


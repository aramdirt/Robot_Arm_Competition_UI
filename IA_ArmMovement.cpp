#include "stdafx.h"
#include "IA_ArmMovement.h"
#include "IA_ObjDef.h"

#define SPEED_L 15
#define SPEED_H 80

//int test = 0;
CArm* CIA_ArmInfo::IA_Arm				= NULL;
CGripper* CIA_ArmInfo::IA_Gripper		= NULL;
//CArmDevice* CIA_ArmInfo::IA_ArmDevice	= NULL;

CObject* Objects;
CBox* Boxes;

//========================================初始化=================================================//
CIA_ArmInfo::CIA_ArmInfo()
{
	Objects = new CObject[18];
	Boxes   = new CBox[5];
	IA_Initialize();
	cnt = 0 ;
	motion = 0;
	i=0;
	j=0;
    w=0;
	delay_cnt = 0;
	SpeedValue = 10;

	Height_of_Classify = 30;
	Height_of_Hole_Box = 30;
	Height_of_Pole_Box = 30;
	Height_of_Fasten = 30;
	Height_of_Catch = 5;

	TargetEular.Pitch = -90;
	TargetEular.Roll = 0;
	TargetEular.Yaw = 0;
	Height_of_Obj = 10.0;

	Boxes[0].Set_Position(-30,48.5);/////////////////////////圓洞盒
	Boxes[0].Set_BoxType(eHole_Box);
	Boxes[1].Set_Position(-16,68.3);
	Boxes[1].Set_BoxType(eAssortingBolt_Box);
	Boxes[2].Set_Position(-16,55.3);///////////////////////////分類盒
	Boxes[2].Set_BoxType(eAssortingNutWasher_Box);
	Boxes[3].Set_Position(-30,76.5);
	Boxes[3].Set_BoxType(ePole_Box);
	Boxes[4].Set_Position(-30,62.5);
	Boxes[4].Set_BoxType(eBolt_Box);
}
//////////////////////////////////////////////////////////////////////////////////
void CIA_ArmInfo::IA_Initialize()
{
	cnt = 0 ;
	motion = 0;
	i=0;
	j=0;
	w=0;
	delay_cnt = 0;
	/*AssortingBolt_Box_X = -16;
	AssortingBolt_Box_Y = 68.3;
	AssortingNutWasher_Box_X = -16;
	AssortingNutWasher_Box_Y = 55.3;
	Hole_Box_X = -30;
	Hole_Box_Y = 48.5;
	Pole_Box_X = -30;
	Pole_Box_Y = 76.5;
	Bolt_Box_X = -30;
	Bolt_Box_Y = 62.5;*/

	Boxes[0].Set_Position(Hole_Box_X,Hole_Box_Y);                               //圓洞盒
	Boxes[0].Set_BoxType(eHole_Box);
	Boxes[1].Set_Position(AssortingBolt_Box_X,AssortingBolt_Box_Y);             //螺栓分類盒
	Boxes[1].Set_BoxType(eAssortingBolt_Box);
	Boxes[2].Set_Position(AssortingNutWasher_Box_X,AssortingNutWasher_Box_Y);   //螺帽墊片分類盒
	Boxes[2].Set_BoxType(eAssortingNutWasher_Box);
	Boxes[3].Set_Position(Pole_Box_X,Pole_Box_Y);                               //圓柱盒                  
	Boxes[3].Set_BoxType(ePole_Box);  
	Boxes[4].Set_Position(Bolt_Box_X,Bolt_Box_Y);                               //鎖螺帽盒
	Boxes[4].Set_BoxType(eBolt_Box);
	
	TargetEular.Pitch = -90;
	TargetEular.Roll = 0;
	TargetEular.Yaw = 0;
	Height_of_Obj = 10.0;
	Height_of_Camera = 36;

	MoveZ = 0.1;
	Mission_Type = /*eGet_Image;*/ePut_In_Washer1; 
	CurrentMissionType = ePut_In_Washer1;

	CameraCoordinate_R.x = 27.5;//30;//25.5;
	CameraCoordinate_R.y = 48.5;//44;//50;
	CameraCoordinate_R.z = Height_of_Camera;//36;//22;//36;
	CameraCoordinate_L.x = 28;//27.5;//30;//25.5;
	CameraCoordinate_L.y = 72;//75;//72;
	CameraCoordinate_L.z = Height_of_Camera;//36;//22;//36;
	CameraEular.Pitch = -90;
	CameraEular.Roll = 90;
	CameraEular.Yaw = 0;

    //影像中心為攝影機中心正下方之座標
	ImgCenterArmCoordinate_R[0] = 31.7;//29.7;//30.61;//34.4;//34.4;         //第一區影像中心手臂座標 X
	ImgCenterArmCoordinate_R[1] = 47.7;//49.1;//49.34;//43.8;//43.5;//43.8         //第一區影像中心手臂座標 Y
	ImgCenterArmCoordinate_L[0] = 32.27;//30.31;//34.7;//34.4;         //第二區影像中心手臂座標 X
	ImgCenterArmCoordinate_L[1] = 71.2;//71.11;//74.5;//74.8;         //第二區影像中心手臂座標 Y

	MappingScaleX = 0.0761;//0.0755;//0.0785;//0.07857405;//0.0785;//0.05;//0.0549286189027335;	    //對影像 X 方向做比例映射
	MappingScaleY = 0.0777;//0.0753;//0.076;//0.07485;//0.076;//0.0510467;//0.76;//0.05455;			//對影像 Y 方向做比例映射(手臂y)

	ArmX_ErrorValue = 0;
	ArmY_ErrorValue = 0.3;
	ArmX_ErrorBase = 1;//6
	ArmY_ErrorBase = 12.25;

	ImgPixelX = 640;
	ImgPixelY = 480;

	ImgEdgeX_Left  = 640;//610;//587;
	ImgEdgeX_Right = 0;//10; //32;
	ImgEdgeY_Front = 480;//400;//370;
	ImgEdgeY_Back  = 0;//80; //102;

	TakeImgTimes = 0;       // times of read Image data
	TakeImgTotalTimes = 20; // times of total reading data
	TaskFlow_Step = 0;

	CameraCoordinate2nd_Flag = false;
	Img2ndAreaCheck_Flag = false;
	Vector_Size = 0;

}
//=========================================初始化結束===============================================//
void CIA_ArmInfo::Get_Objects(CObject* Objptr)
{
	Objects = Objptr;
}

void CIA_ArmInfo::IA_Set_Device( CArm* ArmPtr, CGripper* GripperPtr/*,CArmDevice* ArmDevicePtr*/)
{
	IA_Arm = ArmPtr;
	IA_Gripper = GripperPtr;
	//IA_ArmDevice = ArmDevicePtr;
}//siang
bool CIA_ArmInfo::CheckArmCatch()
{
	int IOPort[2] = {16,17};
	bool DO_Temp16,DO_Temp17;
	//____Port____
	//__16_|__17__
	//	 F |   T	有夾到物件
	//	 T |   T	無夾到物件

	CLeapIO48::Read_DI_SingleBit(0, IOPort[0], &DO_Temp16);
	CLeapIO48::Read_DI_SingleBit(0, IOPort[1], &DO_Temp17);

	if((DO_Temp16 == true) && (DO_Temp17 == true)) return false;
	else if((DO_Temp16 == true) && (DO_Temp17 == false)) return true;
}

void CIA_ArmInfo::Task_Flow()
{
	/*---任務流程---*/
	switch(TaskFlow_Step)
	{
	case 0:
		Get_Info();
		break;
	case 1:
        ImgTest_Mode();
		//Simple_Mission();
		break;
	case 2:
		Mission_Excute();
		break;
	default:
		break;
	}
}
//==================================================影像程式開始==========================================================//
void CIA_ArmInfo::Initial_ImgObjMapInfo()
{
	/*---初始化權重值Map及Vector---*/
	vObject.clear();
	vNut.clear();
	vBolt.clear();
    vWasher.clear();
	ImageMap = NULL;
	ImageMap = new tsWeightMap*[ImgPixelX + 1];
	for(int i = 0; i < ( ImgPixelX + 1 ); i++) ImageMap[i] = new tsWeightMap[ImgPixelY + 1];	
}

void CIA_ArmInfo::Initial_ProhibitedAreaMap()
{
	ProhibitedAreaMap = NULL;
	ProhibitedAreaMap = new bool*[ImgPixelX + 1];
	for(int  i = 0; i < (ImgPixelX + 1); i++) ProhibitedAreaMap[i] = new bool[ImgPixelY + 1];

	for(int X = 0; X < ( ImgPixelX + 1 ); X++)
	{
		for(int Y = 0; Y < ( ImgPixelY + 1 ); Y++)
		{
			if((X >= ImgEdgeX_Left)
				||(X <= ImgEdgeX_Right) 
				||(Y >= ImgEdgeY_Front)
				||(Y <= ImgEdgeY_Back))
			{
				ProhibitedAreaMap[X][Y] = true;	//初始不可夾取範圍
			}
			else
			{
				ProhibitedAreaMap[X][Y] = false;
			}
		}
	}
}
void CIA_ArmInfo::LimitedArea(double Tar_x, double Tar_y)
{
	/*---禁夾區曲線判斷---*/
    Limited_Flag = false;
	double coef_a = -0.0093;
    double coef_b = 0.2508;
	double coef_c = 92.0184;
	double curve_function = Tar_y - (coef_a*Tar_x*Tar_x) - (coef_b*Tar_x) - coef_c;
	if(curve_function > 0)
	{
		Limited_Flag = true;
	}
	else
	{
		Limited_Flag = false;
	}
}
void CIA_ArmInfo::Get_Info()
{
	/*---取得影像資訊---*/
	if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
	{
		if(CurrentMissionType/*Mission_Type*/ != eGet_Image)
		{
			if(CameraCoordinate2nd_Flag)
			{
				/*---切換攝影機讀取位置---*/
				CurrentMissionType = eGet_Image;
				ArmMoveTo_CameraCoordinate(1);	//到攝影機位置2
				Initial_ImgObjMapInfo();		//初始化圖層
				CurrentMissionType = eGet_Image;
				CameraCoordinate2nd_Flag = false;
				Img2ndAreaCheck_Flag = true;
			}
			else
			{
 				CurrentMissionType = eGet_Image;
 				ArmMoveTo_CameraCoordinate(0);	//到攝影機位置1
 				Initial_ImgObjMapInfo();		//初始化圖層
				Img2ndAreaCheck_Flag = false;
 			}
		}
		else
		{
			Set_ImageMapStack();	//讀取影像資訊
		}
		//if(vTaskBox.empty()) Set_vTaskBox();
	}
	
}

// teArmMissionType CIA_ArmInfo::Get_Mission()
// {
// 	;
// }

void CIA_ArmInfo::Set_ImgVarInfo(bool Variable_Flag,int Variable_TotalNum,ScrewParam* Variable_ObjectInfo)
{
	ImageFlag		= Variable_Flag;
	ImgObjTotalNum	= Variable_TotalNum;
	ImageObjectInfo	= Variable_ObjectInfo;

// 	if(ImageFlag == true)
// 	{
// 		printf("SetImgFunc");
// 	}
}

void CIA_ArmInfo::Set_ImageMapStack()
{
	if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
	{
		if(ImageFlag)
		{
			ImageFlag = false;
			ImageInfoStack(ImgObjTotalNum,ImageObjectInfo);
			++delay_cnt;
			if(delay_cnt > 10)       //延遲攝影機讀取有效資料時間(避免攝影機震盪)
			{
				++TakeImgTimes;
			}
			
			//cout << "ImgTimes" << TakeImgTimes << endl ;

			if(TakeImgTimes == TakeImgTotalTimes)
			{
				if(vObject.empty() == false)
				{
					Set_vObjectType();
					Set_vObjectAngle();
					Set_vObjectSequence();
					TakeImgTimes = 0;
					delay_cnt = 0;
					if(ImgTest_Flag)
					{
						TaskFlow_Step = 1;

					}
					else
					{
						TaskFlow_Step = 2;
					}
					
				}
				else
				{
					Initial_ProhibitedAreaMap();
					Initial_ImgObjMapInfo();
					TakeImgTimes = 0;
					delay_cnt = 0;
					CurrentMissionType = ePut_In_Washer1;
 					CameraCoordinate2nd_Flag = true;
 					TaskFlow_Step = 0;
 					Task_Flow();
				}
			}
			else
			{
				
				TaskFlow_Step = 0;
			}
		}
	}
}
void CIA_ArmInfo::ImageInfoStack(int TotalObjNum,ScrewParam* ImgObjInfoPtr)
{
	/*---將權重值加至權重Map中---*/
	int ImgX,ImgY;
	int ImgWeight;
	double ImgAngle;
	ScrewParam ImgObjInfo;

	for(int Num = 0; Num < TotalObjNum; Num++)
	{
		ImgObjInfo = CorrectImgObjCoordinate(ImgObjInfoPtr[Num]);
		ImgX = ImgObjInfo.nx;
		ImgY = ImgObjInfo.ny;
		ImgAngle = ImgObjInfo.fAngle;
		//cout<<"\nImgX = "<<ImgX <<"\tImgY = "<<ImgY<<"\n";
		switch( ImgObjInfo.nClassId )
		{
		case 0 :
			
			ImageMap[ImgX][ImgY].WeightofNut = 1;        //螺帽權重值為 1
			ImageMap[ImgX][ImgY].WeightofBolt = 0;
			ImageMap[ImgX][ImgY].WeightofWasher = 0;
			ImageMap[ImgX][ImgY].dRotation = ImgAngle;
			Set_vObject(ImgX,ImgY,ImageMap);
			break;

		case 1 :
			ImageMap[ImgX][ImgY].WeightofNut = 0;        //螺栓權重值為 1
			ImageMap[ImgX][ImgY].WeightofBolt = 1;
			ImageMap[ImgX][ImgY].WeightofWasher = 0;
			ImageMap[ImgX][ImgY].dRotation = ImgAngle;
			Set_vObject(ImgX,ImgY,ImageMap);
			break;

		case 2:
			ImageMap[ImgX][ImgY].WeightofNut = 0;        //墊片權重值為 1
			ImageMap[ImgX][ImgY].WeightofBolt = 0;
			ImageMap[ImgX][ImgY].WeightofWasher = 1;
			ImageMap[ImgX][ImgY].dRotation = ImgAngle;
			Set_vObject(ImgX,ImgY,ImageMap);
			break;

		default:
			break;
		}
	}
}

void CIA_ArmInfo::Set_vObject(int ObjX, int ObjY, tsWeightMap** Imgweightmap)
{
	/*將權重Map的座標值及權重值設定至物件內*/

	vector<CObject>::iterator itObject;
	CObject PushObject;
	double RotationTemp;
	bool UniqueFlag = true;

	PushObject.Set_Position(ObjX, ObjY);
	PushObject.WeightofNut = Imgweightmap[ObjX][ObjY].WeightofNut;
	PushObject.WeightofBolt = Imgweightmap[ObjX][ObjY].WeightofBolt;
	PushObject.WeightofWasher = Imgweightmap[ObjX][ObjY].WeightofWasher;
	//PushObject.weight = tsWeightMap[ObjX][ObjY].Weight;
	RotationTemp = Imgweightmap[ObjX][ObjY].dRotation;

	for(itObject = vObject.begin(); itObject != vObject.end(); itObject++)
	{
		if((abs(itObject->Get_x() - ObjX) <= 10) && (abs(itObject->Get_y() - ObjY) <= 10))
		{
			//itObject->weight += Sign(PushObject.weight);
			itObject->WeightofNut += PushObject.WeightofNut;
			itObject->WeightofBolt += PushObject.WeightofBolt;
			itObject->WeightofWasher += PushObject.WeightofWasher;
			itObject->vRotation.push_back(RotationTemp);
			UniqueFlag = false;
		}
	}
	if(UniqueFlag == true)
	{
		PushObject.vRotation.push_back(RotationTemp);
		vObject.push_back(PushObject);
	}
}

void CIA_ArmInfo::Set_vObjectType()
{
	/*---根據有效資訊的閾值做物件分類---*/
	vector<CObject>::iterator itObject;

	for(itObject = vObject.begin(); itObject != vObject.end(); itObject++)
	{
		if(itObject->Get_WeightofNut() >= 8)
		{
			itObject->Set_ObjType(eNut);
		}
		else if(itObject->Get_WeightofBolt() >= 8)
		{
			itObject->Set_ObjType(eBolt);
		}
		else if(itObject->Get_WeightofWasher() >= 8)
		{
			itObject->Set_ObjType(eWasher);
		}
		//itObject->Set_ObjType() = ((itObject->weight) >= 0) ? IntelAssortStartBox->Nuts : IntelAssortStartBox->Screw;
	}
}
void CIA_ArmInfo::Set_vObjectAngle()
{
	//cout<<"------------vObject-----------"<<endl; //test
	/*---設定物件角度---*/

	vector<CObject>::iterator itObject;
	for(itObject = vObject.begin(); itObject != vObject.end(); itObject++)
	{
		if(itObject->Get_ObjType() == eBolt)
		{
			double angle = Set_BoltAngle(itObject->Get_x(),itObject->Get_y(),itObject->vRotation);
			itObject->Set_Rotation(angle);
		}
		else
		{
			itObject->Set_Rotation(0);
		}
	}
	//cout<<"--------------------------------"<<endl; //test
}

double CIA_ArmInfo::Set_BoltAngle(int BoltX, int BoltY, vector<double> vBoltAngle)
{
	//cout<<"Set_BoltAngle"<<endl;
	int VectorSize = vBoltAngle.size();
	int UniqueCount = 0;
	double* Unique = new double[VectorSize]; 
	int* Count = new int[VectorSize];
	int CountTemp = 0;
	int setTemp = 0;
	double ReturnAngle;

	for (int i = 0; i < VectorSize; ++i) 
	{ 
		bool bUnique = true; 
		for (int j = 0; j < UniqueCount; ++j) 
		{ 
			if (vBoltAngle.at(i) == Unique[j])
			{ 
				++Count[j]; 
				bUnique = false; 
				break; 
			} 
		}
		if (bUnique) 
		{ 
			Unique[UniqueCount] = vBoltAngle.at(i); 
			Count[UniqueCount] = 1; 
			++UniqueCount; 
		} 
	}
	for (int k = 0; (k < VectorSize) && (Count[k] != 0); ++k) 
	{ 
		if(CountTemp < Count[k])
		{
			CountTemp = Count[k];
			setTemp = k;
		}
	}
	Unique[setTemp] += 90;
	Unique[setTemp] = (Unique[setTemp] >= 360) ? (Unique[setTemp] - 360) : Unique[setTemp];
	if(Unique[setTemp] > 180) Unique[setTemp] = Unique[setTemp] - 360;
	if(abs(Unique[setTemp]) >= 170) Unique[setTemp] = Sign(Unique[setTemp])*170;
	ReturnAngle = Unique[setTemp];

	//cout<<"Angle :"<<ReturnAngle<<endl;
	delete Unique;
	delete Count;
	return ReturnAngle;
}

void CIA_ArmInfo::Set_vObjectSequence()
{
	/*---將vObject做分類後分別存取並按照權重值做排序---*/

	vector<CObject>::iterator itObject;
	int i = 0, j = 0;
	CObject temp1,temp2,temp3;

	for(itObject = vObject.begin(); itObject != vObject.end(); itObject++)
	{
		if(itObject->Get_ObjType() == eNut)
		{
			vNut.push_back(*itObject);
		}
		else if(itObject->Get_ObjType() == eBolt)
		{
            //cout << "set vbolt" << endl ;
			vBolt.push_back(*itObject);
		}
		else if(itObject->Get_ObjType() == eWasher)
		{
			vWasher.push_back(*itObject);
		}
	}
	/*----------------Set Total Object Vector (Classified)------------------*/
	for(itObject = vObject.begin(); itObject != vObject.end(); itObject++)
	{
		if(itObject->Get_ObjType() == eNut || itObject->Get_ObjType() == eBolt || itObject->Get_ObjType() == eWasher)
		{
			vTotalSortObj.push_back(*itObject);
		}
	}
	/*------------------------------Bubble Sort-----------------------------*/
	if(vNut.empty() == false)
	{
		for(int i = 0; i < vNut.size(); i++)
		{
			for(int j = i; j < vNut.size(); j++)
			{
				if(vNut[j].WeightofNut > vNut[i].WeightofNut)
				{
					temp1 = vNut[j];
					vNut[j] = vNut[i];
					vNut[i] = temp1;
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(vBolt.empty() == false)
	{
		for(int i = 0; i < vBolt.size(); i++)
		{
			for(int j = i; j < vBolt.size(); j++)
			{
				if(vBolt[j].WeightofBolt > vBolt[i].WeightofBolt)
				{
					temp2 = vBolt[j];
					vBolt[j] = vBolt[i];
					vBolt[i] = temp2;
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////
	if(vWasher.empty() == false)
	{
		for(int i = 0; i < vWasher.size(); i++)
		{
			for(int j = i; j < vWasher.size(); j++)
			{
				if(vWasher[j].WeightofWasher > vWasher[i].WeightofWasher)
				{
					temp3 = vWasher[j];
					vWasher[j] = vWasher[i];
					vWasher[i] = temp3;
				}
			}
		}
	}
}

ScrewParam CIA_ArmInfo::CorrectImgObjCoordinate(ScrewParam ImgObj)
{
	ImgObj.nx += ImgObj.nWidth/2;		//0830 Test
	ImgObj.ny += ImgObj.nHeight/2;

	if(ImgObj.nx >= ImgPixelX) ImgObj.nx = ImgPixelX;
	if(ImgObj.ny >= ImgPixelX) ImgObj.ny = ImgPixelY;
	if(ImgObj.nx <= 0) ImgObj.nx = 0;
	if(ImgObj.ny <= 0) ImgObj.ny = 0;

	return ImgObj;

}

double* CIA_ArmInfo::MappingImgToArm(int ImgX,int ImgY)
{
	/*將影像座標修正後轉成手臂座標*/

	const int ImgCenterX = ImgPixelX/2, ImgCenterY = ImgPixelY/2;
	int ImgRelX,ImgRelY;
	double ArmX,ArmY;
	double* pArmXY = new double[2];

	ImgRelX = ImgX - ImgCenterX;	// 影像 X
	ImgRelY = ImgY - ImgCenterY;	// 影像 Y

	// MappingScaleX 映射到手臂 X 之倍率
	// MappingScaleY 映射到手臂 Y 之倍率
	
	// 對手臂 X 做線性補償
	//* (ArmX_ErrorValue / ArmX_ErrorBase);
	// 對手臂 Y 做線性補償
	//* (ArmY_ErrorValue / ArmY_ErrorBase);
	
	//兩區攝影機座標點修正
	if(Img2ndAreaCheck_Flag)
	{
		ArmX = ImgCenterArmCoordinate_L[0] - (ImgRelY * MappingScaleX) - ((ImgRelX * MappingScaleY) * (ArmY_ErrorValue / ArmY_ErrorBase)/*(ImgRelY * MappingScaleX) * (ArmX_ErrorValue / ArmX_ErrorBase)*/);
		ArmY = ImgCenterArmCoordinate_L[1] - (ImgRelX * MappingScaleY) /*- ((ImgRelX * MappingScaleY) * (ArmY_ErrorValue / ArmY_ErrorBase))*/;
	}
	else
	{
		ArmX = ImgCenterArmCoordinate_R[0] - (ImgRelY * MappingScaleX) - ((ImgRelX * MappingScaleY) * (ArmY_ErrorValue / ArmY_ErrorBase)/*(ImgRelY * MappingScaleX) * (ArmX_ErrorValue / ArmX_ErrorBase)*/);
		ArmY = ImgCenterArmCoordinate_R[1] - (ImgRelX * MappingScaleY) /*- ((ImgRelX * MappingScaleY) * (ArmY_ErrorValue / ArmY_ErrorBase))*/;
	}
	
	pArmXY[0] = ArmX;
	pArmXY[1] = ArmY;
	return pArmXY;
}

void CIA_ArmInfo::ArmMoveTo_CameraCoordinate(int tag)
{
	/*---移至攝影機位置---*/
	CVector3D Goal;
	tsEulerAngle Eular;

	if(tag == 0)
	{
		Goal = CameraCoordinate_R;
		//CameraCoordinate_Flag = true;
	}
	else if(tag == 1)
	{
		Goal = CameraCoordinate_L;
		//CameraCoordinate_Flag = false;
	}

	Eular = CameraEular;
	GripperCatch(CGripper::eCMD_BACKHOME);
	ArmMove(PtP, Abs, Goal, Eular, SpeedValue);
}
//==================================================影像程式結束========================================================//
tsEulerAngle CIA_ArmInfo::Get_ArmEularDegree()
{
	tsEulerAngle EularDegree = IA_Arm->Get_EndEuler();

	EularDegree.Pitch	*= 180/M_PI;
	EularDegree.Roll	*= 180/M_PI;
	EularDegree.Yaw		*= 180/M_PI;
	EularDegree.Rot		*= 180/M_PI;

	return EularDegree;
}

teArmMissionType* CIA_ArmInfo::Set_TargetObject_GoalEular()
{
	teArmMissionType* Type = new teArmMissionType;

	//vector<information_object>::iterator itObject;

	return Type;
}

void CIA_ArmInfo::ArmMove(tePL PtP_Line,teRA Rel_Abs,CVector3D Goal,tsEulerAngle Eular,double Speed)
{
	/*---控制手臂函式(Command)---*/
	//cout<<"ArmMove Goal : "<<Goal.x<<" "<<Goal.y<<" "<<Goal.z<<endl;
	//cout<<"ArmMove Eular: "<<Eular.Pitch<<" "<<Eular.Roll<<" "<<Eular.Yaw<<endl;
	//弧度和角度轉換//
	Eular.Pitch *=	M_PI / 180.0;
	Eular.Roll	*=	M_PI / 180.0;
	Eular.Yaw	*=	M_PI / 180.0;

	switch(PtP_Line)
	{
	case tePL::PtP:
		if(Rel_Abs == teRA::Rel)		    IA_Arm->PtoP->Command(CPtoP::eMOVE_REL, Goal, Eular);
		else if(Rel_Abs == teRA::Abs)	    IA_Arm->PtoP->Command(CPtoP::eMOVE_ABS, Goal, Eular);
		break;

	case tePL::Line:
		if(Rel_Abs == teRA::Rel)		    IA_Arm->Line->Command(CPtoP::eMOVE_REL, Goal, Eular);
		else if(Rel_Abs == teRA::Abs)	    IA_Arm->Line->Command(CPtoP::eMOVE_ABS, Goal, Eular);
		break;

	default:
		break;
	}
	IA_Arm->Set_SpeedPercent(Speed);
}

//======================================================================================================================//
double CIA_ArmInfo::ObjToArm_Rotation(CObject* obj)
{
	/*---將讀取物件的旋轉度轉成手臂ROLL的旋轉度---*/
	if(obj->Get_Rotation() >= 179.0)
	{
		return (obj->Get_Rotation()-358.0);
	}
	else
	{
		return (obj->Get_Rotation());
	}
}
//======================================================================================================================//
// void CIA_ArmInfo::Obstacle(teSelectObjType objtype)
// {
// 	/*---避障---*/
// // 	vector<CObject>::iterator itObject;
// // 	double Com_ObjX, Com_ObjY, Tar_ObjX, Tar_ObjY;
// 	Vector_Size = 0;
// 	w=0;
// 
// 	do 
// 	{
// 		vector<CObject>::iterator itObject;
// 		double Com_ObjX, Com_ObjY, Tar_ObjX, Tar_ObjY;
// 		//double* ArmXY= new double[2];
// 		IsTouch_Flag = false;
// 		
// 		if(vTotalSortObj.empty() == false)
// 		{
// 			for(itObject = vTotalSortObj.begin(); itObject != vTotalSortObj.end(); itObject++)
// 			{
// 				//cout << vTotalSortObj.size() << endl;
// 				double* ArmXY= new double[2];
// 				ArmXY = MappingImgToArm(itObject->Get_x(),itObject->Get_y());        //比較全部物件的座標轉換
// 				Com_ObjX = ArmXY[0];
// 				Com_ObjY = ArmXY[1];
// 
// 				switch(objtype)
// 				{
// 				case eNut:
// 					ArmXY = MappingImgToArm(vNut[w].Get_x(),vNut[w].Get_y());        //欲夾取物件的座標轉換
// 					Tar_ObjX = ArmXY[0];
// 					Tar_ObjY = ArmXY[1];
// 					Vector_Size = vNut.size();
// 					break;
// 				case eBolt:
// 					ArmXY = MappingImgToArm(vBolt[w].Get_x(),vBolt[w].Get_y());      //欲夾取物件的座標轉換
// 					Tar_ObjX = ArmXY[0];
// 					Tar_ObjY = ArmXY[1];
// 					Vector_Size = vBolt.size();
// 					break;
// 				case eWasher:
// 					ArmXY = MappingImgToArm(vWasher[w].Get_x(),vWasher[w].Get_y());  //欲夾取物件的座標轉換
// 					Tar_ObjX = ArmXY[0];
// 					Tar_ObjY = ArmXY[1];
// 					Vector_Size = vWasher.size();
// 					break;
// 				}
// 				delete ArmXY;
// 
// 				if(Com_ObjX != Tar_ObjX && Com_ObjY != Tar_ObjY)
// 				{
// 					if(itObject->Get_ObjType() == eBolt)
// 					{
// 						if((sqrt(pow(Com_ObjX - Tar_ObjX, 2) + pow(Com_ObjY - Tar_ObjY, 2)) < 7.5))
// 						{
// 							IsTouch_Flag = true;			
// 						}
// 					}
// 					else if(itObject->Get_ObjType() == eNut || itObject->Get_ObjType() == eWasher)
// 					{
// 						if((sqrt(pow(Com_ObjX - Tar_ObjX, 2) + pow(Com_ObjY - Tar_ObjY, 2)) < 6))
// 						{
// 							IsTouch_Flag = true;			
// 						}
// 					}
// 				}
// 			}
// 		}
// 		if(IsTouch_Flag == true)  //取權重排序次小(之後)物件
// 		{
// 			w++;
// 		}
// 		//delete ArmXY;
// 
// 	} while (IsTouch_Flag == true && w < /*vWasher.size()*/Vector_Size);
// }
//======================================================================================================================//
float CIA_ArmInfo::degree_to_pi(float degree)
{
	/*---角度單位轉換(度度換徑度)副函式---*/	
	return degree*3.1415926/180.0;
}
//=================================================動作執行=============================================================//
void CIA_ArmInfo::Mission_Excute()
{
	switch(Mission_Type)
	{
	case ePut_In_Washer1:
		//============================放墊片(1)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				//IsTouch_Flag = true;
                if(vWasher.empty() == true || w >= vWasher.size())
				{
					CurrentMissionType = ePut_In_Washer1;
					CameraCoordinate2nd_Flag = true;
					w=0;
					end_point_roll=0;
					TaskFlow_Step = 0;
					Task_Flow();
				}
				else
				{
					Obstacle();
					if(IsTouch_Flag == false && w < vWasher.size())
					{
						Arm_MoveToTargetUpside_Washer();
						motion ++;
						//i++;
						j=0;
					}
					else
					{
						CurrentMissionType = ePut_In_Washer1;
						CameraCoordinate2nd_Flag = true;
						TaskFlow_Step = 0;
						w=0;
						end_point_roll=0;
						Task_Flow();
					}
					
				}
				break;
			case 1:
				Arm_GetDegree(eWasher);
				i++;
				motion ++;
				break;
			case 2:
				Arm_DownPtP(/*eWasher*/);
				motion ++;
				break;
			case 3:
				Arm_DownLine();
				motion ++;
				break;
			case 4:
				Arm_Catch();
				motion ++;
				break;
			case 5:
				Calibrate_Width1();
				motion++;
				break;
			case 6:
				Calibrate_Up_Little();
				motion++;
				break;
			case 7:
				Calibrate_Roll90();
				motion++;
				break;
			case 8:
				Arm_DownLine();
				motion++;
				break;
			case 9:
				Arm_Catch();
				motion++;
				break;
			case 10:
				Arm_UpLine();
				motion ++;
				break;
			case 11: 
				//Arm_OriginDegree();
				motion ++;
				break;
			case 12:
				Arm_CatchUpPtP_Washer(); 
				motion ++;///////box0
				break;
			case 13:
				Arm_DownLine_Hole_Box_Washer();
				motion ++;
				break;
			case 14:
				Arm_Loosen();
				motion ++;
				break;
			case 15:
				Arm_Up_PtoP();
				motion++;
				break;
			case 16:
				Arm_OriginDegree();
				motion ++;
				break;
			case 17:
				Arm_Stop();
				CurrentMissionType = Mission_Type ;
				Mission_Type = eInsert_Bolt;
				motion=0;
				CameraCoordinate2nd_Flag = false;
				TaskFlow_Step = 0;
				w=0;
				end_point_roll=0;
				Task_Flow();
				break;
			default:
				break;
			}
		}
		break;
////////////////////////////////////////////////////////////////////////////////////////		
	case eInsert_Bolt:
		//============================插螺栓(2)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				if(vBolt.empty() == true || w >= vBolt.size())
				{
					CurrentMissionType = eInsert_Bolt;
					CameraCoordinate2nd_Flag = true;
					TaskFlow_Step = 0;
					w=0;
					Task_Flow();
				}
				else
				{
					Obstacle1();
					if(IsTouch_Flag == false && w < vBolt.size())
					{
						Arm_MoveToTargetUpside_Bolt();
						//i++;
						j=0;
						motion ++;
					}
					else
					{
						CurrentMissionType = eInsert_Bolt;
						CameraCoordinate2nd_Flag = true;
						TaskFlow_Step = 0;
						w=0;
						Task_Flow();
					}
				}
				break;
			case 1:
				//Arm_GetDegree(eBolt);
				i++;
				motion ++;
				break;
			case 2:
				Arm_DownPtP(/*eBolt*/);
				motion ++;
				break;
			case 3:
				Arm_DownLine();
				motion ++;
				break;
			case 4:
				Arm_Catch();
				motion ++;
				break;
			case 5:
				Arm_UpLine();
				motion ++;
				break;
			case 6:
				Arm_OriginDegree();
				motion ++;
				break;
			case 7:
				//Arm_InsertBolt_TurnPos();
				motion ++;
				break;
			case 8:
				Arm_InsertBolt_EularDeg();
				motion ++;
				break;
			case 9:
				Arm_Put_Bolt();///////box0
				motion ++;
				break;
			case 10:
				Arm_DownLine_Hole_Box_Bolt();
				motion ++;
				break;
			case 11:
				//Arm_Loosen();
				Arm_BackHome();
				motion ++;
				break;
			case 12:
				Arm_Up_PtoP();
				motion ++;
				break;
			case 13:
				Arm_InsertBolt_EularDeg();
				motion++;
				break;
			case 14:
				Arm_InsertBolt_TurnPos();
				motion ++;
				break;
			case 15:
				Arm_OriginDegree();
				motion ++;
				break;
			case 16:
				Arm_Stop();	
				CurrentMissionType = Mission_Type ;
				Mission_Type = ePut_In_Nut;
				motion = 0;
				CameraCoordinate2nd_Flag = false;
				TaskFlow_Step = 0;
				w=0;
				end_point_roll = 0;
				Task_Flow();
				break;
			default:
				break;
			}
		}
		break;
/////////////////////////////////////////////////////////////////////////////////////////
	case ePut_In_Nut:
		//===========================放螺帽(跑2次)(3)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				if(vNut.empty() == true || w >= vNut.size())
				{
					CurrentMissionType = ePut_In_Nut;
					CameraCoordinate2nd_Flag = true;
					w=0;
					end_point_roll = 0;
					TaskFlow_Step = 0;
					Task_Flow();
				}
				else
				{
					Obstacle2();
					if(IsTouch_Flag == false && w < vNut.size())
					{
						Arm_MoveToTargetUpside_Nut();
						motion++;
						//i++;
						j = 3;
					}
					else
					{
						CurrentMissionType = ePut_In_Nut;
						CameraCoordinate2nd_Flag = true;
						w=0;
						end_point_roll=0;
						TaskFlow_Step = 0;
						Task_Flow();
					}
				}
				break;
			case 1:
				Arm_GetDegree(eNut);
				motion++;
				break;
			case 2:
				Arm_DownPtP(/*eNut*/);
				motion++;
				break;
			case 3:
				Arm_DownLine();
				motion++;
				break;
			case 4:
				Arm_Catch();
				motion++;
				break;
			case 5:
				Calibrate_Width1();
				motion++;
				break;
			case 6:
				Calibrate_Up_Little();
				motion++;
				break;
			case 7:
				Calibrate_Roll90();
				motion++;
				break;
			case 8:
				Arm_DownLine();
				motion++;
				break;
			case 9:
				Arm_Catch();
				motion++;
				break;
			case 10:
				Arm_UpLine();
				motion++;
				break;
			case 11:
				Arm_CatchUpPtP();/////box3
				motion++;
				break;
			case 12:
				Arm_DownLine_Pole_Box();
				motion++;
				break;
			case 13:
				Arm_Loosen();
				motion++;
				break;
			case 14:
				Arm_Up_PtoP();
				motion++;
				break;
			case 15:
				Arm_OriginDegree();
				motion++;
				break;
			case 16:
				Arm_Stop();
				//int cnt = 0;
				cnt++;
				if(cnt == 2)
				{
					CurrentMissionType = Mission_Type;
					Mission_Type = ePut_In_Washer2;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					w=0;
					end_point_roll=0;
					TaskFlow_Step = 0;
					Task_Flow();
					cnt = 0;
				}
				else
				{
					CurrentMissionType = Mission_Type ;
					Mission_Type = ePut_In_Nut;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					w=0;
					TaskFlow_Step = 0;
					Task_Flow();
				}
			default:
				break;
			}
		}
		break;
////////////////////////////////////////////////////////////////////////////////////////
	case ePut_In_Washer2:
		//===========================放墊片(4)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				if(vWasher.empty() == true || w >= vWasher.size())
				{
					CurrentMissionType = ePut_In_Washer2;
					CameraCoordinate2nd_Flag = true;
					w=0;
					end_point_roll=0;
					TaskFlow_Step = 0;
					Task_Flow();
				}
				else
				{
					Obstacle();
					if(IsTouch_Flag == false && w < vWasher.size())
					{
						Arm_MoveToTargetUpside_Washer();
						motion ++;
						//i++;
						j=4;
					}
					else
					{
						CurrentMissionType = ePut_In_Washer2;
						CameraCoordinate2nd_Flag = true;
						w=0;
						end_point_roll=0;
						TaskFlow_Step = 0;
						Task_Flow();
					}
					
				}
				break;
			case 1:
				Arm_GetDegree(eWasher);
				motion ++;
				break;
			case 2:
				Arm_DownPtP(/*eWasher*/);
				motion ++;
				break;
			case 3:
				Arm_DownLine();
				motion ++;
				break;
			case 4:
				Arm_Catch();
				motion ++;
				break;
			case 5:
				Calibrate_Width1();
				motion++;
				break;
			case 6:
				Calibrate_Up_Little();
				motion++;
				break;
			case 7:
				Calibrate_Roll90();
				motion++;
				break;
			case 8:
				Arm_DownLine();
				motion++;
				break;
			case 9:
				Arm_Catch();
				motion++;
				break;
			case 10:
				Arm_UpLine();
				motion ++;
				break;
			case 11:
				Arm_CatchUpPtP();////box4
				motion ++;
				break;
			case 12:
				Arm_DownLine_Bolt_Box();
				motion ++;
				break;
			case 13:
				Arm_Loosen();
				motion ++;
				break;
			case 14:
				Arm_Up_PtoP();
				motion++;
				break;
			case 15:
				Arm_OriginDegree();
				motion = 0;
				CurrentMissionType = Mission_Type ;
				Mission_Type = eFasten_Nut;
				CameraCoordinate2nd_Flag = false;
				w=0;
				end_point_roll=0;
				TaskFlow_Step = 0;
				Task_Flow();
				break;
			default:
				break;
			}
		}
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////
	case eFasten_Nut:				
		//===========================鎖螺帽(5)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				if(vNut.empty() == true || w >= vNut.size())
				{
					CurrentMissionType = eFasten_Nut;
					CameraCoordinate2nd_Flag = true;
					w=0;
					end_point_roll=0;
					TaskFlow_Step = 0;
					Task_Flow();
				}
				else
				{
					Obstacle2();
					if(IsTouch_Flag == false && w < vNut.size())
					{
						Arm_MoveToTargetUpside_Nut();
						motion++;
						//i = 0;
						j=4;
					}
					else
					{
						CurrentMissionType = eFasten_Nut;
						CameraCoordinate2nd_Flag = true;
						w=0;
						TaskFlow_Step = 0;
						end_point_roll=0;
						Task_Flow();
					}
					
				}
				break;
			case 1:
				Arm_GetDegree(eNut);
				motion++;
				break;
			case 2:
				Arm_DownPtP(/*eNut*/);
				motion++;
				break;
			case 3:
				Arm_DownLine();
				motion++;
				break;
			case 4:
				Arm_Catch();
				motion++;
				break;
			case 5:
				Calibrate_Width1();
				motion++;
				break;
			case 6:
				Calibrate_Up_Little();
				motion++;
				break;
			case 7:
				Calibrate_Roll90();
				motion++;
				break;
			case 8:
				Arm_DownLine();
				motion++;
				break;
			case 9:
				Arm_Catch();
				motion++;
				break;
			case 10:
				Arm_UpLine();
				motion++;
				break;
			case 11:
				Arm_CatchUpPtP();
				motion++;
				break;
			case 12:
				Arm_DownLine_Bolt_Box();
				motion++;
				break;
				//==========================fasten 1st
			case 13:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 14:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 15:
				Arm_Loosen();         
				motion++;
				break;
// 			case 10:
// 				Arm_MoveDown();        //z move down 0.5
// 				MoveZ = 1;
// 				motion++;
// 				break;
			case 16:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 17:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 2nd
			case 18:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 19:
				Arm_Loosen();
				motion++;
				break;
			case 20:
				Arm_Fasten_Back();   //Roll turn to -80
				motion++;
				break; 
			case 21:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 3rd
			case 22:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 23:
				Arm_Loosen();
				motion++;
				break;
			case 24:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 25:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 4th
			case 26:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 27:
				Arm_Loosen();
				motion++;
				break;
			case 28:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 29:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 5th
			case 30:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 31:
				Arm_Loosen();
				motion++;
				break;
			case 32:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 33:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 6th
			case 34:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 35:
				Arm_Loosen();
				motion++;
				break;
			case 36:
// 				Arm_MoveDown();        //z move down 0.5
// 				MoveZ = 1.5;
				motion++;
				break;
			case 37:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 38:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 7th
			case 39:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 40:
				Arm_Loosen();
				motion++;
				break;
			case 41:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 42:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 8th
			case 43:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 44:
				Arm_Loosen();
				motion++;
				break;
			case 45:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 46:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 9th
			case 47:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 48:
				Arm_Loosen();
				motion++;
				break;
			case 49:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 50:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 10th
			case 51:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 52:
				Arm_Loosen();
				motion++;
				break;
			case 53:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 54:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 11th
			case 55:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 56:
				Arm_Loosen();
				motion++;
				break;
			case 57:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 58:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 12th
			case 59:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 60:
				Arm_Loosen();
				motion++;
				break;
			case 61:
				Arm_Fasten_Back();    //Roll turn to -80
				motion++;
				break;
			case 62:
				Arm_Catch();
				motion++;
				break;
				//==========================fasten 13th
// 			case 58:
// 				Arm_Fasten();          //Roll turn to +80
// 				MoveZ += 0.1;
// 				motion++;
// 				break;
// 			case 59:
// 				Arm_Loosen();
// 				motion++;
// 				break;
// 			case 60:
// 				Arm_Fasten_Back();    //Roll turn to -80
// 				motion++;
// 				break;
// 			case 61:
// 				Arm_Catch();
// 				motion++;
// 				break;
// 				//==========================fasten 14th
// 			case 62:
// 				Arm_Fasten();          //Roll turn to +80
// 				MoveZ += 0.1;
// 				motion++;
// 				break;
// 			case 63:
// 				Arm_Loosen();
// 				motion++;
// 				break;
// 			case 64:
// 				Arm_Fasten_Back();    //Roll turn to -80
// 				motion++;
// 				break;
// 			case 65:
// 				Arm_Catch();
// 				motion++;
// 				break;
				//==========================fasten 15th
			case 63:
				Arm_Fasten();          //Roll turn to +80
				MoveZ += 0.1;
				motion++;
				break;
			case 64:
				Arm_Loosen();
				motion++;
				break;
			case 65:
				Arm_Up_PtoP();
				motion++;
				break;
			case 66:
				Arm_OriginDegree();   //EularAngle turn back to -90,0,0
				motion++;
				break;
			case 67:
				Arm_Stop();
				motion = 0;
				CurrentMissionType = Mission_Type ;
				Mission_Type = eClassify_Nut;
				CameraCoordinate2nd_Flag = false;
				w=0;
				end_point_roll=0;
				TaskFlow_Step = 0;
				Task_Flow();
				break;
			default:
				break;
			}
		}
		break;
////////////////////////////////////////////////////////////////////////////////////
	case eClassify_Nut:					
		//===========================分類螺帽(跑4次)(7)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				if(vNut.empty() == true || w >= vNut.size())
				{
					if(Img2ndAreaCheck_Flag == false)
					{
						CurrentMissionType = eClassify_Nut;
						CameraCoordinate2nd_Flag = true;
						TaskFlow_Step = 0;
						w=0;
						end_point_roll=0;
						Task_Flow();
					}
					else
					{
						if(cnt >= 4)
						{
							CurrentMissionType = Mission_Type;
							Mission_Type = eClassify_Washer;
							motion = 0;
							CameraCoordinate2nd_Flag = false;
							TaskFlow_Step = 0;
							cnt = 0;
							w=0;
							end_point_roll=0;
							Task_Flow();
						}
						else
						{
							CurrentMissionType = eClassify_Nut;
							CameraCoordinate2nd_Flag = false;
							cnt++;
							TaskFlow_Step = 0;
							w=0;
							end_point_roll=0;
							Task_Flow();
						}
					}
				}
				else
				{
					Obstacle2();
					if (IsTouch_Flag != true && w < vNut.size())
					{
						Arm_MoveToTargetUpside_Nut();
						motion++;
						//i++;
						j = 2;
					}
					else
					{
						if (Img2ndAreaCheck_Flag == false)
						{
							CurrentMissionType = eClassify_Nut;
							CameraCoordinate2nd_Flag = true;
							TaskFlow_Step = 0;
							w=0;
							end_point_roll=0;
							Task_Flow();
						}
						else
						{
							if (cnt >= 4)
							{
								CurrentMissionType = Mission_Type;
								Mission_Type = eClassify_Washer;
								motion = 0;
								CameraCoordinate2nd_Flag = false;
								TaskFlow_Step = 0;
								w=0;
								end_point_roll=0;
								cnt = 0;
								Task_Flow();
							}
							else
							{
								CurrentMissionType = eClassify_Nut;
								CameraCoordinate2nd_Flag = false;
								cnt++;
								TaskFlow_Step = 0;
								w=0;
								end_point_roll=0;
								Task_Flow();
							}
						}
					}
					
				}
				break;
			case 1:
				Arm_GetDegree(eNut);
				motion++;
				break;
			case 2:
				Arm_DownPtP(/*eNut*/);
				motion++;
				break;
			case 3:
				Arm_DownLine();
				motion++;
				break;
			case 4:
				Arm_Catch();
				motion++;
				break;
			case 5:
				Arm_UpLine();
				motion++;
				break;
			case 6:
				Arm_CatchUpPtP();//////box2
				motion++;
				break;
			case 7:
				Arm_DownPtP_Assorting_Box();
				motion++;
				break;
			case 8:
				Arm_Loosen();
				motion++;
				break;
			case 9:
				Arm_Up_PtoP();
				motion++;
				break;
			case 10:
				Arm_OriginDegree();
				motion++;
				break;
			case 11:
				Arm_Stop();
				//int cnt = 0;
				cnt++;
				if(cnt == 4)
				{
					CurrentMissionType = Mission_Type;
					Mission_Type = eClassify_Washer;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					TaskFlow_Step = 0;
					w=0;
					end_point_roll=0;
					Task_Flow();
					cnt = 0;
				}
				else
				{
					CurrentMissionType = Mission_Type ;
					Mission_Type = eClassify_Nut;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					TaskFlow_Step = 0;
					w=0;
					end_point_roll=0;
					Task_Flow();
				}
			default:
				break;
			}
		}
		break;
//////////////////////////////////////////////////////////////////////////////////
	case eClassify_Washer:				
		//===========================分類墊片(跑4次)(8)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				if(vWasher.empty() == true || w >= vWasher.size())
				{
					if(Img2ndAreaCheck_Flag == false)
					{
						CurrentMissionType = eClassify_Washer;
						CameraCoordinate2nd_Flag = true;
						TaskFlow_Step = 0;
						w=0;
						end_point_roll=0;
						Task_Flow();
					}
					else
					{
						if(cnt >= 4)
						{
							CurrentMissionType = Mission_Type;
							Mission_Type = eClassify_Bolt;
							motion = 0;
							CameraCoordinate2nd_Flag = false;
							TaskFlow_Step = 0;
							cnt = 0;
							w=0;
							end_point_roll=0;
							Task_Flow();
						}
						else
						{
							CurrentMissionType = eClassify_Washer;
							CameraCoordinate2nd_Flag = false;
							cnt++;
							w=0;
							end_point_roll=0;
							TaskFlow_Step = 0;
							Task_Flow();
						}
					}
				}
				else
				{
					Obstacle();
					if (IsTouch_Flag != true && w < vWasher.size())
					{
						Arm_MoveToTargetUpside_Washer();
						motion ++;
						//i++;
						j = 2;	
					}
					else
					{
						if (Img2ndAreaCheck_Flag == false)
						{
							CurrentMissionType = eClassify_Washer;
							CameraCoordinate2nd_Flag = true;
							TaskFlow_Step = 0;
							w=0;
							end_point_roll=0;
							Task_Flow();
						}
						else
						{
							if (cnt >= 4)
							{
								CurrentMissionType = Mission_Type;
								Mission_Type = eClassify_Bolt/*eClassify_Nut*/;
								motion = 0;
								CameraCoordinate2nd_Flag = false;
								TaskFlow_Step = 0;
								w=0;
								end_point_roll=0;
								cnt = 0;
								Task_Flow();
							}
							else
							{
								CurrentMissionType = eClassify_Washer;
								CameraCoordinate2nd_Flag = false;
								cnt++;
								TaskFlow_Step = 0;
								w=0;
								end_point_roll=0;
								Task_Flow();
							}
						}
					}		
				}
				break;
			case 1:
				Arm_GetDegree(eWasher);
				motion ++;
				break;
			case 2:
				Arm_DownPtP(/*eWasher*/);
				motion ++;
				break;
			case 3:
				Arm_DownLine();
				motion ++;
				break;
			case 4:
				Arm_Catch();
				motion ++;
				break;
			case 5:
				Arm_UpLine();
				motion ++;
				break;
			case 6:
				Arm_CatchUpPtP_Washer();/////box2
				motion ++;
				break;
			case 7:
				Arm_DownPtP_Assorting_Box();
				motion ++;
				break;
			case 8:
				Arm_Loosen();
				motion ++;
				break;
			case 9:
				Arm_Up_PtoP();
				motion++;
				break;
			case 10:
				Arm_OriginDegree();
				motion ++;
				break;
			case 11:
				Arm_Stop();
				//int cnt = 0;
				cnt++;
				if(cnt == 4)
				{
					CurrentMissionType = Mission_Type;
					Mission_Type = eClassify_Bolt;
					motion = 0;
					w=0;
					end_point_roll=0;
					CameraCoordinate2nd_Flag = false;					
 					TaskFlow_Step = 0;
// 					Task_Flow();
 					cnt = 0;
					Task_Flow();
				}
				else
				{
					CurrentMissionType = Mission_Type ;
					Mission_Type = eClassify_Washer;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					TaskFlow_Step = 0;
					w=0;
					end_point_roll=0;
					Task_Flow();
				}
			default:
				break;
			}
		}
		break;
//////////////////////////////////////////////////////////////////////////////////
	case eClassify_Bolt:
		//===========================分類螺栓(跑4次)(6)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				if(vBolt.empty() == true || w >= vBolt.size())
				{
					if(Img2ndAreaCheck_Flag == false)
					{
						/*判斷第一區找不到物件*/
						CurrentMissionType = eClassify_Bolt;
						CameraCoordinate2nd_Flag = true;
						TaskFlow_Step = 0;
						w=0;
						end_point_roll=0;
						Task_Flow();
					}
					else
					{
						/*判斷第二區找不到物件*/
						if(cnt>=4)
						{
							CurrentMissionType = Mission_Type;
							Mission_Type = eLeavedObject;
							motion = 0;
							CameraCoordinate2nd_Flag = false;
							cnt = 0;
							TaskFlow_Step = 0;
							w=0;
							end_point_roll=0;
							Task_Flow();

						}
						else
						{
							CurrentMissionType = eClassify_Bolt;
							CameraCoordinate2nd_Flag = false;
							cnt++;
							w=0;
							end_point_roll=0;
							TaskFlow_Step = 0;
							Task_Flow();
						}
					}
				}
				else
				{
					//加避障
					Obstacle1();
					if (IsTouch_Flag != true && w < vBolt.size())
					{
						Arm_MoveToTargetUpside_Bolt();
						motion++;
						//i++;
						j = 1;
					}
					else
					{
						if (Img2ndAreaCheck_Flag == false)
						{
							CurrentMissionType = eClassify_Bolt;
							CameraCoordinate2nd_Flag = true;
							TaskFlow_Step = 0;
							w=0;
							end_point_roll=0;
							Task_Flow();
						}
						else
						{
							if (cnt >= 4)
							{
								CurrentMissionType = Mission_Type;
								Mission_Type = eLeavedObject;
								motion = 0;
								CameraCoordinate2nd_Flag = false;
								TaskFlow_Step = 0;
								w=0;
								end_point_roll=0;
								cnt = 0;
								Task_Flow();
							}
							else
							{
								CurrentMissionType = eClassify_Bolt;
								CameraCoordinate2nd_Flag = false;
								cnt++;
								TaskFlow_Step = 0;
								Task_Flow();
							}
						}
					}

				}
				break;
			case 1:
				//Arm_GetDegree(eBolt);
				motion++;
				i++;
				break;
			case 2:
				Arm_DownPtP(/*eBolt*/);
				motion++;
				break;
			case 3:
				DownLineClassify();
				motion++;
				break;
			case 4:
				Arm_Catch();
				motion++;
				break;
			case 5:
				Arm_UpLine();
				motion++;
				break;
			case 6:
				//Arm_OriginDegree();
				motion ++;
				break;
			case 7:
				Arm_CatchUpPtP();////box1
				motion++;
				break;
			case 8:
				Arm_DownPtP_Assorting_Box();
				motion++;
				break;
			case 9:
				Arm_Loosen();
				motion++;
				break;
			case 10:
				Arm_Up_PtoP();
				motion++;
				break;
			case 11:
				Arm_OriginDegree();
				motion++;
				break;
			case 12:
				Arm_Stop();
				//int cnt = 0;
				cnt++;
				if(cnt == 4)
				{
					CurrentMissionType = Mission_Type;
					Mission_Type = eLeavedObject;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					TaskFlow_Step = 0;
					w=0;
					end_point_roll=0;
					Task_Flow();
					cnt = 0;
				}
				else
				{
					CurrentMissionType = Mission_Type ;
					Mission_Type = eClassify_Bolt;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					TaskFlow_Step = 0;
					w=0;
					end_point_roll=0;
					Task_Flow();
				}
				break;
			default:
				break;
			}
		}
		break;
//////////////////////////////////////////////////////////////////////////////////
	case eLeavedObject:
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			//bool garbage_flag = false;
			switch(motion)
			{
			case 0:
				//bool garbage_flag = false;
				if(vNut.empty() == true && vWasher.empty() == true && vBolt.empty() == true)
				{
					CurrentMissionType = eLeavedObject;
					CameraCoordinate2nd_Flag = true;
					w=0;
					TaskFlow_Step = 0;
					Task_Flow();
				}
				else
				{
					w=0;
					if(vNut.empty() == false)
					{
						double* ArmXY= new double[2];
						ArmXY = MappingImgToArm(vNut[w].Get_x(),vNut[w].Get_y());
						obj_x = ArmXY[0];
						obj_y = ArmXY[1];
						delete ArmXY;
						LimitedArea(obj_x,obj_y);
						if(Limited_Flag == true)
						{
							w++;
						}
					}
					if(vNut.empty() == false && w < vNut.size())
					{
						Arm_MoveToTargetUpside_Nut();
						motion++;
						j = 2;
						w=0;
					}
					w=0;
					if(vWasher.empty() == false)
					{
						double* ArmXY= new double[2];
						ArmXY = MappingImgToArm(vWasher[w].Get_x(),vWasher[w].Get_y());
						obj_x = ArmXY[0];
						obj_y = ArmXY[1];
						delete ArmXY;
						LimitedArea(obj_x,obj_y);
						if(Limited_Flag == true)
						{
							w++;
						}
					}
					if(vWasher.empty() == false && w < vWasher.size())
					{
						Arm_MoveToTargetUpside_Washer();
						motion++;
						j = 2;
						w=0;
					}
					w=0;
					if(vBolt.empty() == false)
					{
						double* ArmXY= new double[2];
						ArmXY = MappingImgToArm(vBolt[w].Get_x(),vBolt[w].Get_y());
						obj_x = ArmXY[0];
						obj_y = ArmXY[1];
						delete ArmXY;
						LimitedArea(obj_x,obj_y);
						if(Limited_Flag == true)
						{
							w++;
						}
					}
					if(vBolt.empty() == false && w < vBolt.size())
					{
						Arm_MoveToTargetUpside_Bolt();
						motion++;
						j = 1;
						//w=0;
					}
// 					if(vNut.empty() == false)
// 					{
// 						double* ArmXY= new double[2];
// 						ArmXY = MappingImgToArm(vNut[w].Get_x(),vNut[w].Get_y());
// 						obj_x = ArmXY[0];
// 						obj_y = ArmXY[1];
// 						delete ArmXY;
// 
// 						LimitedArea(obj_x,obj_y);
// 						if(Limited_Flag == false && w < vNut.size())
// 						{
// 							//w=0;
// 							Arm_MoveToTargetUpside_Nut();
// 							motion++;
// 							j = 2;
// 							w=0;
// 							//garbage_flag = true;
// 						}
// 					}
// 					else if(vWasher.empty() == false /*&& garbage_flag == false*/)
// 					{
// 						double* ArmXY= new double[2];
// 						ArmXY = MappingImgToArm(vWasher[0].Get_x(),vWasher[0].Get_y());
// 						obj_x = ArmXY[0];
// 						obj_y = ArmXY[1];
// 						delete ArmXY;
// 
// 						LimitedArea(obj_x,obj_y);
// 						if(Limited_Flag == false && w < vWasher.size())
// 						{
// 							w=0;
// 							Arm_MoveToTargetUpside_Washer();
// 							motion++;
// 							j = 2;
// 							//garbage_flag = true;
// 						}
// 					}
// 					else if(vBolt.empty() == false /*&& garbage_flag == false*/)
// 					{
// 						double* ArmXY= new double[2];
// 						ArmXY = MappingImgToArm(vBolt[0].Get_x(),vBolt[0].Get_y());
// 						obj_x = ArmXY[0];
// 						obj_y = ArmXY[1];
// 						delete ArmXY;
// 
// 						LimitedArea(obj_x,obj_y);
// 						if(Limited_Flag == false)
// 						{
// 							w=0;
// 							Arm_MoveToTargetUpside_Bolt();
// 							motion++;
// 							//i++;
// 							j = 1;
// 							//garbage_flag = true;
// 						}
// 					}
				}
				break;
			case 1:
				//Arm_GetDegree(eNut);
				motion++;
				break;
			case 2:
				Arm_DownPtP(/*eNut*/);
				motion++;
				break;
			case 3:
				Arm_DownLine();
				motion++;
				break;
			case 4:
				Arm_Catch();
				motion++;
				break;
			case 5:
				Arm_UpLine();
				motion++;
				break;
			case 6:
				Arm_CatchUpPtP();//////box2
				motion++;
				break;
			case 7:
				Arm_DownPtP_Assorting_Box();
				motion++;
				break;
			case 8:
				Arm_Loosen();
				motion++;
				break;
			case 9:
				Arm_Up_PtoP();
				motion++;
				break;
			case 10:
				Arm_OriginDegree();
				motion++;
				break;
			case 11:
				Arm_Stop();
				//int cnt = 0;
				cnt++;
				if(cnt == 8)
				{
					CurrentMissionType = Mission_Type;
					Mission_Type = eLeavedObject/*eMission_End*/;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					TaskFlow_Step = 0;
					Task_Flow();
					cnt = 0;
				}
				else
				{
					CurrentMissionType = Mission_Type ;
					Mission_Type = eLeavedObject;
					motion = 0;
					CameraCoordinate2nd_Flag = false;
					TaskFlow_Step = 0;
					Task_Flow();
				}
			default:
				break;
			}
		}
		break;

	case eMission_End:
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			Mission_Type = eMission_End;
			Arm_Stop();
		}
		break;

	default:
		break;
	}
}
//==========================================影像誤差測試模式=================================================//
void CIA_ArmInfo::ImgTest_Mode()
{
	switch(eClassify_Washer)
	{
	case eClassify_Washer:				
		//===========================分類墊片(跑4次)(8)
		if((IA_Arm->IsBusy() == false) && (IA_Gripper->ISBusy() == false))
		{
			switch(motion)
			{
			case 0:
				if(vWasher.empty() == true && vNut.empty() == true)
				{
					CurrentMissionType = eClassify_Washer;
					CameraCoordinate2nd_Flag = true;
					TaskFlow_Step = 0;
					Task_Flow();
				}
				else
				{
					Arm_MoveToTargetUpside_ClassifyWasherNut();
					motion ++;
					//i++;
					j = 2;			
				}
				break;
			case 1:
				//Arm_GetDegree(eWasher);
				motion ++;
				break;
			case 2:
				Arm_DownPtP(/*eWasher*/);
				motion ++;
				break;
			case 3:
				Arm_DownLine();
				motion ++;
				break;
			case 4:
				//Arm_OriginDegree();
				motion ++;
				break;
			case 5:
				Arm_Stop();
				//int cnt = 0;
// 				CurrentMissionType = Mission_Type ;
// 				Mission_Type = eClassify_Washer;
// 				motion = 0;
// 				CameraCoordinate2nd_Flag = false;
// 				TaskFlow_Step = 0;
// 				Task_Flow();
			default:
				break;
			}
		}
		break;
	default:
		break;
	}
}

//================================================動作函式=============================================//
void CIA_ArmInfo::Arm_MoveToTargetUpside_Washer()
{
	/*到墊片上方10公分處轉好夾取角度*/
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;
	double* ArmXY= new double[2];

	ArmXY = MappingImgToArm(vWasher[w].Get_x(),vWasher[w].Get_y());
	TargetGoal.x = ArmXY[0];
	TargetGoal.y = ArmXY[1];
	delete ArmXY;

// 	TargetGoal.x = Objects[i].Get_x();
// 	TargetGoal.y = Objects[i].Get_y();
	
// 	if(Img2ndAreaCheck_Flag)
// 	{
// 		if(TargetGoal.y < 60)
// 		{
// 			TargetGoal.y = TargetGoal.y-0.2;
// 		}
// 		else
// 		{
// 			TargetGoal.y = TargetGoal.y;
// 		}
// 	}
// 	else
// 	{
// 		if(TargetGoal.y > 64)
// 		{
// 			TargetGoal.y = TargetGoal.y+1;
// 		}
// 		else if(TargetGoal.y < 40)
// 		{
// 			TargetGoal.y = TargetGoal.y-0.2;
// 		}
// 		else
// 		{
// 			TargetGoal.y = TargetGoal.y;
// 		}
// 	}
// 
// 	if(TargetGoal.x > 38)
// 	{
// 		TargetGoal.x = TargetGoal.x+0.6;
// 	}
// 	else
// 	{
// 		TargetGoal.x = TargetGoal.x;
// 	}

	TargetEular.Roll = 0;                   //轉回 Roll=0 夾物件
	Abs_Eular.Pitch	= TargetEular.Pitch;    //目標姿態 Pitch
	Abs_Eular.Roll	= TargetEular.Roll;		//目標姿態 Roll
	Abs_Eular.Yaw	= TargetEular.Yaw;		//目標姿態 Yaw

	XValue = TargetGoal.x;
	YValue = TargetGoal.y;

	ZValue = Height_of_Obj;
	Abs_Goal.x = TargetGoal.x;				//目標座標 X
	Abs_Goal.y = TargetGoal.y;				//目標座標 Y
	Abs_Goal.z = Height_of_Obj;				//目標上方高度
	GripperCatch(CGripper::eCMD_CATCHTO1);
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_MoveToTargetUpside_Nut()
{
	/*到螺帽上方10公分處轉好夾取角度*/
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;
    double* ArmXY= new double[2];

	ArmXY = MappingImgToArm(vNut[w].Get_x(),vNut[w].Get_y());
	TargetGoal.x = ArmXY[0];
	TargetGoal.y = ArmXY[1];
	delete ArmXY;

// 	TargetGoal.x = vNut[0].Get_x();
// 	TargetGoal.y = vNut[0].Get_y();

// 	if(Img2ndAreaCheck_Flag)
// 	{
// 		if(TargetGoal.y < 60)
// 		{
// 			TargetGoal.y = TargetGoal.y-0.2;
// 		}
// 		else
// 		{
// 			TargetGoal.y = TargetGoal.y;
// 		}
// 	}
// 	else
// 	{
// 		if(TargetGoal.y > 64)
// 		{
// 			TargetGoal.y = TargetGoal.y+1;
// 		}
// 		else if(TargetGoal.y < 40)
// 		{
// 			TargetGoal.y = TargetGoal.y-0.2;
// 		}
// 		else
// 		{
// 			TargetGoal.y = TargetGoal.y;
// 		}
// 	}

// 	if(TargetGoal.x > 38)
// 	{
// 		TargetGoal.x = TargetGoal.x+0.6;
// 	}
// 	else
// 	{
// 		TargetGoal.x = TargetGoal.x;
// 	}

	TargetEular.Roll = 0;                   //轉回 Roll=0 夾物件
	Abs_Eular.Pitch	= TargetEular.Pitch;    //目標姿態 Pitch
	Abs_Eular.Roll	= TargetEular.Roll;		//目標姿態 Roll
	Abs_Eular.Yaw	= TargetEular.Yaw;		//目標姿態 Yaw

	XValue = TargetGoal.x;
	YValue = TargetGoal.y;

	ZValue = Height_of_Obj;
	Abs_Goal.x = TargetGoal.x;				//目標座標 X
	Abs_Goal.y = TargetGoal.y;				//目標座標 Y
	Abs_Goal.z = Height_of_Obj;				//目標上方高度
	GripperCatch(CGripper::eCMD_CATCHTO1);
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_MoveToTargetUpside_Bolt()     
{
    /*到螺栓上方10公分處轉好夾取角度*/
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;
	double* ArmXY= new double[2];

	ArmXY = MappingImgToArm(vBolt[w].Get_x(),vBolt[w].Get_y());
	TargetGoal.x = ArmXY[0];
	TargetGoal.y = ArmXY[1];
	delete ArmXY;

// 	TargetGoal.x = vBolt[0].Get_x();
// 	TargetGoal.y = vBolt[0].Get_y();

// 	if(Img2ndAreaCheck_Flag)
// 	{
// 		if(TargetGoal.y < 60)
// 		{
// 			TargetGoal.y = TargetGoal.y-0.2;
// 		}
// 		else
// 		{
// 			TargetGoal.y = TargetGoal.y;
// 		}
// 	}
// 	else
// 	{
// 		if(TargetGoal.y > 64)
// 		{
// 			TargetGoal.y = TargetGoal.y+1;
// 		}
// 		else if(TargetGoal.y < 40)
// 		{
// 			TargetGoal.y = TargetGoal.y-0.2;
// 		}
// 		else
// 		{
// 			TargetGoal.y = TargetGoal.y;
// 		}
// 	}
// 
// 	if(TargetGoal.x > 38)
// 	{
// 		TargetGoal.x = TargetGoal.x+0.6;
// 	}
// 	else
// 	{
// 		TargetGoal.x = TargetGoal.x;
// 	}

	TargetEular.Roll = ObjToArm_Rotation(&vBolt[w]);  //轉成螺栓旋轉角度
	Abs_Eular.Pitch	= TargetEular.Pitch;    //目標姿態 Pitch
	Abs_Eular.Roll	= TargetEular.Roll;		//目標姿態 Roll
	Abs_Eular.Yaw	= TargetEular.Yaw;		//目標姿態 Yaw

	XValue = TargetGoal.x;
	YValue = TargetGoal.y;

	ZValue = Height_of_Obj;
	Abs_Goal.x = TargetGoal.x;				//目標座標 X
	Abs_Goal.y = TargetGoal.y;				//目標座標 Y
	Abs_Goal.z = Height_of_Obj;				//目標上方高度
	GripperCatch(CGripper::eCMD_CATCHTO1);
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_MoveToTargetUpside_ClassifyWasherNut()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;
	double* ArmXY= new double[2];

	if(vWasher.empty() == false)
	{
		ArmXY = MappingImgToArm(vWasher[0].Get_x(),vWasher[0].Get_y());
	}
	else if(vNut.empty() == false)
	{
		ArmXY = MappingImgToArm(vNut[0].Get_x(),vNut[0].Get_y());
	}

	//ArmXY = MappingImgToArm(vWasher[0].Get_x(),vWasher[0].Get_y());
	TargetGoal.x = ArmXY[0];
	TargetGoal.y = ArmXY[1];
	delete ArmXY;

	// 	TargetGoal.x = Objects[i].Get_x();
	// 	TargetGoal.y = Objects[i].Get_y();
// 	if(Img2ndAreaCheck_Flag)
// 	{
// 		if(TargetGoal.y < 60)
// 		{
// 			TargetGoal.y = TargetGoal.y-0.2;
// 		}
// 		else
// 		{
// 			TargetGoal.y = TargetGoal.y;
// 		}
// 	}
// 	else
// 	{
// 		if(TargetGoal.y > 64)
// 		{
// 			TargetGoal.y = TargetGoal.y+1;
// 		}
// 		else if(TargetGoal.y < 40)
// 		{
// 			TargetGoal.y = TargetGoal.y-0.2;
// 		}
// 		else
// 		{
// 			TargetGoal.y = TargetGoal.y;
// 		}
// 	}
// 
// 	if(TargetGoal.x > 38)
// 	{
// 		TargetGoal.x = TargetGoal.x+0.6;
// 	}
// 	else
// 	{
// 		TargetGoal.x = TargetGoal.x;
// 	}

	TargetEular.Roll = 0;                   //轉回 Roll=0 夾物件 
	Abs_Eular.Pitch	= TargetEular.Pitch;    //目標姿態 Pitch
	Abs_Eular.Roll	= TargetEular.Roll;		//目標姿態 Roll
	Abs_Eular.Yaw	= TargetEular.Yaw;		//目標姿態 Yaw

	XValue = TargetGoal.x;
	YValue = TargetGoal.y;

	ZValue = Height_of_Obj;
	Abs_Goal.x = TargetGoal.x;				//目標座標 X
	Abs_Goal.y = TargetGoal.y;				//目標座標 Y
	Abs_Goal.z = Height_of_Obj;				//目標上方高度
	GripperCatch(CGripper::eCMD_CATCHTO1);
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_GetDegree(teSelectObjType objtype)
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	if(objtype == eBolt)
	{
		TargetEular.Roll = ObjToArm_Rotation(&vBolt[w]);
	}
	else if(objtype == eNut)
	{
		TargetEular.Roll = end_point_roll;
	}
	else if(objtype == eWasher)
	{
		TargetEular.Roll = end_point_roll;
	}

	Abs_Eular.Pitch	= TargetEular.Pitch;    //目標姿態 Pitch
	Abs_Eular.Roll	= TargetEular.Roll;		//目標姿態 Roll
	Abs_Eular.Yaw	= TargetEular.Yaw;		//目標姿態 Yaw
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_DownPtP(/*teSelectObjType objtype*/)			//p to p下降
{
	/*減速下降至欲夾取物件上方5公分處*/
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

// 	if(objtype == eBolt)
// 	{
// 		TargetEular.Roll = ObjToArm_Rotation(&vBolt[0]);
// 	}
// 	else if(objtype == eNut)
// 	{
// 		TargetEular.Roll = 0;//ObjToArm_Rotation(&vNut[0]);
// 	}
// 	else if(objtype == eWasher)
// 	{
// 		TargetEular.Roll = 0;//ObjToArm_Rotation(&vWasher[0]);
// 	}
// 
// 	Abs_Eular.Pitch	= TargetEular.Pitch;    //目標姿態 Pitch
// 	Abs_Eular.Roll	= TargetEular.Roll;		//目標姿態 Roll
// 	Abs_Eular.Yaw	= TargetEular.Yaw;		//目標姿態 Yaw

	ZValue = Height_of_Catch + 5;
	Abs_Goal.z = Height_of_Catch + 5; 
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue-20);  
}
void CIA_ArmInfo::Arm_DownPtP_Assorting_Box()			//分類p to p下降
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Classify;
	Abs_Goal.z = Height_of_Classify; 
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_DownLine_Hole_Box_Washer()			//洞洞p to p下降
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Hole_Box;
	Abs_Goal.z = Height_of_Hole_Box ; 
	ArmMove(  Line, Abs, Abs_Goal, Abs_Eular,SPEED_L);
}
void CIA_ArmInfo::Arm_DownLine_Hole_Box_Bolt()			//洞洞盒Line下降
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Hole_Box +2.3;
	Abs_Goal.z = Height_of_Hole_Box + 2.3; 
	ArmMove(  Line, Abs, Abs_Goal, Abs_Eular,SPEED_L);
}
void CIA_ArmInfo::Arm_DownLine_Pole_Box()			   //圓柱盒Line下降
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Pole_Box;
	Abs_Goal.z = Height_of_Pole_Box; 
	ArmMove(  Line, Abs, Abs_Goal, Abs_Eular,SPEED_L);
}
void CIA_ArmInfo::Arm_DownLine_Bolt_Box()			   //鎖入Line下降
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Fasten;
	Abs_Goal.z = Height_of_Fasten; 
	ArmMove(  Line, Abs, Abs_Goal, Abs_Eular,SPEED_L);
}
void CIA_ArmInfo::Arm_DownLine()			//Line下降
{
	
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Catch;
// 	if(Abs_Goal.y >= 62)
// 	{
// 		Abs_Goal.z = Height_of_Catch+0.4;
// 	}else if(Abs_Goal.y >=72)
// 	{
// 		Abs_Goal.z = Height_of_Catch+0.8;
// 	}else
// 	{
// 		Abs_Goal.z = Height_of_Catch;
// 	}

    Abs_Goal.z = Height_of_Catch;
	ArmMove( Line, Abs, Abs_Goal, Abs_Eular,SPEED_L);
}

void CIA_ArmInfo::DownLineClassify()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Catch;
	Abs_Goal.z = Height_of_Catch+0.5;
	ArmMove( Line, Abs, Abs_Goal, Abs_Eular,SPEED_L);

}


void CIA_ArmInfo::Arm_Loosen()			//夾爪鬆開
{
	GripperCatch(CGripper::eCMD_LOOSEN);
}
void CIA_ArmInfo::Arm_Catch()			//夾爪夾取
{
	GripperCatch(CGripper::eCMD_CATCH);
}
void CIA_ArmInfo::Arm_BackHome()        //夾爪全開
{
	GripperCatch(CGripper::eCMD_BACKHOME);
}
void CIA_ArmInfo::Arm_CatchUpPtP()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	TargetGoal.x = Boxes[j].Get_x();
	TargetGoal.y = Boxes[j].Get_y();
	XValue = TargetGoal.x;
	YValue = TargetGoal.y;
	ZValue = 20;
	Abs_Goal.x = TargetGoal.x;				//目標座標 X
	Abs_Goal.y = TargetGoal.y;		
	Abs_Goal.z = 20;

	Abs_Eular.Pitch	= -90;	//恢復姿態 Pitch
	Abs_Eular.Roll	= 0;	//恢復姿態 Roll
	Abs_Eular.Yaw	= 0;

	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular, SpeedValue);  //比全速少10
}
void CIA_ArmInfo::Arm_Put_Bolt()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	TargetGoal.x = -29.6;					//////////////////////////////////////////改成相對於放電片
	TargetGoal.y = 49;//49
	XValue = TargetGoal.x;
	YValue = TargetGoal.y;

	ZValue = 20;
	Abs_Goal.x = TargetGoal.x;				//目標座標 X
	Abs_Goal.y = TargetGoal.y;		
	Abs_Goal.z = 20;
	ArmMove(  Line, Abs, Abs_Goal, Abs_Eular, SpeedValue);
}

void CIA_ArmInfo::Arm_CatchUpPtP_Washer()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	TargetGoal.x = Boxes[j].Get_x();
	TargetGoal.y = Boxes[j].Get_y();
	XValue = TargetGoal.x;
	YValue = TargetGoal.y;
	ZValue = 20;
	Abs_Goal.x = TargetGoal.x;				//目標座標 X
	Abs_Goal.y = TargetGoal.y;		
	Abs_Goal.z = 20;

	Abs_Eular.Pitch	= -90;	//恢復姿態 Pitch
	Abs_Eular.Roll	= 0;	//恢復姿態 Roll
	Abs_Eular.Yaw	= 0;

	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue); //比全速少10
}
void CIA_ArmInfo::Arm_UpLine()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = 7;
	Abs_Goal.z = 7;
	ArmMove( Line, Abs, Abs_Goal, Abs_Eular,SPEED_L);
}

void CIA_ArmInfo::Arm_Up_PtoP()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = 20;
	Abs_Goal.z = 20;
	ArmMove( PtP, Abs, Abs_Goal, Abs_Eular,SPEED_H);//速度80%
}
void CIA_ArmInfo::Arm_MoveDown()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Fasten - MoveZ;
	Abs_Goal.z = Height_of_Fasten - MoveZ;
	ArmMove( Line, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_InsertBolt_EularDeg()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	int step = 0;
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	Abs_Goal.x = 0;
	Abs_Goal.y = 60;
	Abs_Goal.z = 30;

	Abs_Eular.Pitch = 0;
	Abs_Eular.Roll = 0;
	Abs_Eular.Yaw = 0;

	ArmMove( PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_InsertBolt_TurnPos()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	Abs_Goal.x = 0;
	Abs_Goal.y = 60;
	Abs_Goal.z = 30;

	Abs_Eular.Pitch	= -90;	//恢復姿態 Pitch
	Abs_Eular.Roll	= 0;	//恢復姿態 Roll
	Abs_Eular.Yaw	= 0;

	ArmMove( PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_Fasten()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	ZValue = Height_of_Fasten - MoveZ;
	Abs_Goal.z = Height_of_Fasten - MoveZ;

	Abs_Eular.Pitch = -90;
	Abs_Eular.Roll = 80;
	Abs_Eular.Yaw = 0;

	ArmMove( PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_Fasten_Back()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	Abs_Eular.Pitch = -90;
	Abs_Eular.Roll = -80;
	Abs_Eular.Yaw = 0;
	ArmMove( PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}

void CIA_ArmInfo::Arm_MoveBack()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	Abs_Goal.x = TargetGoal.x /*+ MoveX*/;
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}

void CIA_ArmInfo::Arm_OriginDegree()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	Abs_Eular.Pitch	= -90;	//恢復姿態 Pitch
	Abs_Eular.Roll	= 0;	//恢復姿態 Roll
	Abs_Eular.Yaw	= 0;
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}

void CIA_ArmInfo::Calibrate_Up_Little()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;
	Abs_Goal.z = Height_of_Catch;
	ArmMove( Line, Abs, Abs_Goal, Abs_Eular,SPEED_L);
}
void CIA_ArmInfo::Calibrate_Roll90()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;

	Abs_Eular.Pitch	= -90;	//恢復姿態 Pitch
	Abs_Eular.Roll	= end_point_roll-90;	//恢復姿態 Roll
	Abs_Eular.Yaw	= 0;
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Calibrate_Width1()
{
	CVector3D		Abs_Goal(0,0,0);
	tsEulerAngle	Abs_Eular = {0,0,0,0,0};
	const CVector3D&	 End_Pos	=	Get_ArmPos();
	const tsEulerAngle&  End_Eular	=	Get_ArmEularDegree();
	Abs_Goal = End_Pos;
	Abs_Eular= End_Eular;
	GripperCatch(CGripper::eCMD_CATCHTO1);
	ArmMove(  PtP, Abs, Abs_Goal, Abs_Eular,SpeedValue);
}
void CIA_ArmInfo::Arm_Stop()
{	
	ArmStop();
}

void CIA_ArmInfo::Obstacle()			//washer
{
	w=0;
	end_point_roll=0;
	do 
	{
		IsTouch_Flag = false;
		double* ArmXY= new double[2];
		ArmXY = MappingImgToArm(vWasher[w].Get_x(),vWasher[w].Get_y());
		obs_x = ArmXY[0];
		obs_y = ArmXY[1];

		obs_gripper1_x=obs_x+5*cos(degree_to_pi((-end_point_roll) + 22)); //夾爪四端座標點
		obs_gripper1_y=obs_y+5*sin(degree_to_pi((-end_point_roll) + 22));
		obs_gripper2_x=obs_x+5*cos(degree_to_pi((-end_point_roll) - 22));
		obs_gripper2_y=obs_y+5*sin(degree_to_pi((-end_point_roll) - 22));
		obs_gripper3_x=obs_x-5*cos(degree_to_pi((-end_point_roll) + 22));
		obs_gripper3_y=obs_y-5*sin(degree_to_pi((-end_point_roll) + 22));
		obs_gripper4_x=obs_x-5*cos(degree_to_pi((-end_point_roll) - 22));
		obs_gripper4_y=obs_y-5*sin(degree_to_pi((-end_point_roll) - 22));

		obs_gripper5_x=obs_x+2.5*cos(degree_to_pi((-end_point_roll) + 28)); //夾爪四端座標點
		obs_gripper5_y=obs_y+2.5*sin(degree_to_pi((-end_point_roll) + 28));
		obs_gripper6_x=obs_x+2.5*cos(degree_to_pi((-end_point_roll) - 28));
		obs_gripper6_y=obs_y+2.5*sin(degree_to_pi((-end_point_roll) - 28));
		obs_gripper7_x=obs_x-2.5*cos(degree_to_pi((-end_point_roll) + 28));
		obs_gripper7_y=obs_y-2.5*sin(degree_to_pi((-end_point_roll) + 28));
		obs_gripper8_x=obs_x-2.5*cos(degree_to_pi((-end_point_roll) - 28));
		obs_gripper8_y=obs_y-2.5*sin(degree_to_pi((-end_point_roll) - 28));
		//delete ArmXY;
		if(vWasher.empty() == false)
		{
			for(int i= 0; i <vWasher.size(); i++)
			{
				//double* ArmXY= new double[2];
				ArmXY = MappingImgToArm(vWasher[i].Get_x(),vWasher[i].Get_y());
				obsa_x = ArmXY[0];
				obsa_y = ArmXY[1];
				//delete ArmXY;
				if (vWasher[i].Get_x() != vWasher[w].Get_x() && vWasher[i].Get_y() != vWasher[w].Get_y())//self
				{
					//int B = sqrt(pow(obsa_x - obs_x, 2)+pow(obsa_y  - obs_y, 2));
					if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 2) ||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 2) ||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 2 ))
					{
						IsTouch_Flag = true;			
					}
					//break;
				}
			}
		}
		if(vNut.empty() == false)
		{
			for(int i= 0; i <vNut.size(); i++)
			{
				//double* ArmXY= new double[2];
				ArmXY = MappingImgToArm(vNut[i].Get_x(),vNut[i].Get_y());
				obsa_x = ArmXY[0];
				obsa_y = ArmXY[1];
				//delete ArmXY;
				if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 2) 
					||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 2)
					||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 2 )
					||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 2 )
					||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 2) 
					||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 2 )
					||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 2 )
					||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 2 ))
				{
					IsTouch_Flag = true;			
				}
			}
		}
		if(vBolt.empty() == false)
		{
			for(int i= 0; i <vBolt.size(); i++)
			{
				//double* ArmXY= new double[2];
				ArmXY = MappingImgToArm(vBolt[i].Get_x(),vBolt[i].Get_y());
				obsa_x = ArmXY[0];
				obsa_y = ArmXY[1];
				//delete ArmXY;
				if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 4) 
					||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 4 )
					||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 4 )
					||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 4 )
					||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 4 ) 
					||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 4 )
					||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 4 )
					||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 4 ))
				{
					IsTouch_Flag = true;			
				}
			}
		}
		if(IsTouch_Flag == true)
		{
			end_point_roll=end_point_roll + 30.0;
		}

		LimitedArea(obs_x,obs_y);
		if(end_point_roll > 180 || Limited_Flag == true)
		{
			w++;
			end_point_roll = 0;
		}
		delete ArmXY;
		//double* ArmXY= new double[2];
// 		ArmXY = MappingImgToArm(vWasher[w].Get_x(),vWasher[w].Get_y());
// 		obs_x = ArmXY[0];
// 		obs_y = ArmXY[1];
// 		delete ArmXY;
// 		LimitedArea(obs_x,obs_y);
// 		if(Limited_Flag==true)
// 		{
// 			w++;
// 		}

	} while (IsTouch_Flag == true && w < vWasher.size());
}
void CIA_ArmInfo::Obstacle2()//nut
{
	w=0;
	end_point_roll=0;
	do 
	{
		IsTouch_Flag = false;
		double* ArmXY= new double[2];
		ArmXY = MappingImgToArm(vNut[w].Get_x(),vNut[w].Get_y());
		obs_x = ArmXY[0];
		obs_y = ArmXY[1];

		obs_gripper1_x=obs_x+5*cos(degree_to_pi((-end_point_roll) + 22)); //夾爪四端座標點
		obs_gripper1_y=obs_y+5*sin(degree_to_pi((-end_point_roll) + 22));
		obs_gripper2_x=obs_x+5*cos(degree_to_pi((-end_point_roll) - 22));
		obs_gripper2_y=obs_y+5*sin(degree_to_pi((-end_point_roll) - 22));
		obs_gripper3_x=obs_x-5*cos(degree_to_pi((-end_point_roll) + 22));
		obs_gripper3_y=obs_y-5*sin(degree_to_pi((-end_point_roll) + 22));
		obs_gripper4_x=obs_x-5*cos(degree_to_pi((-end_point_roll) - 22));
		obs_gripper4_y=obs_y-5*sin(degree_to_pi((-end_point_roll) - 22));

		obs_gripper5_x=obs_x+2.5*cos(degree_to_pi((-end_point_roll) + 28)); //夾爪四端座標點
		obs_gripper5_y=obs_y+2.5*sin(degree_to_pi((-end_point_roll) + 28));
		obs_gripper6_x=obs_x+2.5*cos(degree_to_pi((-end_point_roll) - 28));
		obs_gripper6_y=obs_y+2.5*sin(degree_to_pi((-end_point_roll) - 28));
		obs_gripper7_x=obs_x-2.5*cos(degree_to_pi((-end_point_roll) + 28));
		obs_gripper7_y=obs_y-2.5*sin(degree_to_pi((-end_point_roll) + 28));
		obs_gripper8_x=obs_x-2.5*cos(degree_to_pi((-end_point_roll) - 28));
		obs_gripper8_y=obs_y-2.5*sin(degree_to_pi((-end_point_roll) - 28));
		//delete ArmXY;
		if(vWasher.empty() == false)
		{
			for(int i= 0; i <vWasher.size(); i++)
			{
				//double* ArmXY= new double[2];
				ArmXY = MappingImgToArm(vWasher[i].Get_x(),vWasher[i].Get_y());
				obsa_x = ArmXY[0];
				obsa_y = ArmXY[1];
				//delete ArmXY;
				//	int B = sqrt(pow(obsa_x - obs_x, 2)+pow(obsa_y  - obs_y, 2));
				if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 2) ||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 2) ||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 2 ))
				{
					IsTouch_Flag = true;			
				}
				//break;
			}
		}
		if(vNut.empty() == false)
		{
			for(int i= 0; i <vNut.size(); i++)
			{
				//double* ArmXY= new double[2];
				ArmXY = MappingImgToArm(vNut[i].Get_x(),vNut[i].Get_y());
				obsa_x = ArmXY[0];
				obsa_y = ArmXY[1];
				//delete ArmXY;
				if (vNut[i].Get_x() != vNut[w].Get_x() && vNut[i].Get_y() != vNut[w].Get_y())
				{
					if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 1.5) ||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 1.5) ||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 1.5 ))
					{
						IsTouch_Flag = true;			
					}
				}
			}
		}
		if(vBolt.empty() == false)
		{
			for(int i= 0; i <vBolt.size(); i++)
			{
				//double* ArmXY= new double[2];
				ArmXY = MappingImgToArm(vBolt[i].Get_x(),vBolt[i].Get_y());
				obsa_x = ArmXY[0];
				obsa_y = ArmXY[1];
				//delete ArmXY;
				if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 4) ||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 4) ||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 4 ))
				{
					IsTouch_Flag = true;			
				}
			}
		}
		if(IsTouch_Flag == true)
		{
			end_point_roll=end_point_roll + 30.0;
		}

		LimitedArea(obs_x,obs_y);
		if(end_point_roll > 180 || Limited_Flag == true)
		{
			w++;
			end_point_roll=0;
		}
		delete ArmXY;
// 		ArmXY = MappingImgToArm(vNut[w].Get_x(),vNut[w].Get_y());
// 		obs_x = ArmXY[0];
// 		obs_y = ArmXY[1];
// 		delete ArmXY;
// 		LimitedArea(obs_x,obs_y);
// 		if(Limited_Flag==true)
// 		{
// 			w++;
// 		}
	} while (IsTouch_Flag == true && w < vNut.size());
}
void CIA_ArmInfo::Obstacle1()/////////bolt
{
	w=0;
	end_point_roll=0;
	do 
	{
		IsTouch_Flag = false;
		double* ArmXY= new double[2];
		ArmXY = MappingImgToArm(vBolt[w].Get_x(),vBolt[w].Get_y());
		obs_x = ArmXY[0];
		obs_y = ArmXY[1];

		obs_gripper1_x=obs_x+5*cos(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) + 22)); //夾爪四端座標點
		obs_gripper1_y=obs_y+5*sin(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) + 22));
		obs_gripper2_x=obs_x+5*cos(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) - 22));
		obs_gripper2_y=obs_y+5*sin(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) - 22));
		obs_gripper3_x=obs_x-5*cos(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) + 22));
		obs_gripper3_y=obs_y-5*sin(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) + 22));
		obs_gripper4_x=obs_x-5*cos(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) - 22));
		obs_gripper4_y=obs_y-5*sin(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) - 22));

		obs_gripper5_x=obs_x+2.5*cos(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) + 28)); //夾爪四端座標點
		obs_gripper5_y=obs_y+2.5*sin(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) + 28));
		obs_gripper6_x=obs_x+2.5*cos(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) - 28));
		obs_gripper6_y=obs_y+2.5*sin(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) - 28));
		obs_gripper7_x=obs_x-2.5*cos(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) + 28));
		obs_gripper7_y=obs_y-2.5*sin(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) + 28));
		obs_gripper8_x=obs_x-2.5*cos(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) - 28));
		obs_gripper8_y=obs_y-2.5*sin(degree_to_pi((-ObjToArm_Rotation(&vBolt[w])) - 28));
		//delete ArmXY;
		if(vWasher.empty() == false)
		{
			for(int i= 0; i <vWasher.size(); i++)
			{
				//double* ArmXY= new double[2];
				ArmXY = MappingImgToArm(vWasher[i].Get_x(),vWasher[i].Get_y());
				obsa_x = ArmXY[0];
				obsa_y = ArmXY[1];
				//delete ArmXY;
				//	int B = sqrt(pow(obsa_x - obs_x, 2)+pow(obsa_y  - obs_y, 2));
				if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 2) ||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 2) ||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 2 )||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 2 ))
				{
					IsTouch_Flag = true;			
				}
				//break;
				//}
			}
		}
		if(vNut.empty() == false)
		{
			for(int i= 0; i <vNut.size(); i++)
			{
				//double* ArmXY= new double[2];
				ArmXY = MappingImgToArm(vNut[i].Get_x(),vNut[i].Get_y());
				obsa_x = ArmXY[0];
				obsa_y = ArmXY[1];
				//delete ArmXY;
				if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 1.5) ||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 1.5) ||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 1.5 )||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 1.5 ))
				{
					IsTouch_Flag = true;			
				}
			}
		}
		if(vBolt.empty() == false)
		{
			for(int i= 0; i <vBolt.size(); i++)
			{
				if (vBolt[i].Get_x() != vBolt[w].Get_x() && vBolt[i].Get_y() != vBolt[w].Get_y())
				{
					//double* ArmXY= new double[2];
					ArmXY = MappingImgToArm(vBolt[i].Get_x(),vBolt[i].Get_y());
					obsa_x = ArmXY[0];
					obsa_y = ArmXY[1];
					//delete ArmXY;
					if((sqrt(pow(obsa_x - obs_gripper1_x, 2)+pow(obsa_y  - obs_gripper1_y, 2)) < 4) ||(sqrt(pow(obsa_x - obs_gripper2_x, 2)+pow(obsa_y  - obs_gripper2_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper3_x, 2)+pow(obsa_y  - obs_gripper3_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper4_x, 2)+pow(obsa_y  - obs_gripper4_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper5_x, 2)+pow(obsa_y  - obs_gripper5_y, 2)) < 4) ||(sqrt(pow(obsa_x - obs_gripper6_x, 2)+pow(obsa_y  - obs_gripper6_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper7_x, 2)+pow(obsa_y  - obs_gripper7_y, 2)) < 4 )||(sqrt(pow(obsa_x - obs_gripper8_x, 2)+pow(obsa_y  - obs_gripper8_y, 2)) < 4 ))
					{
						IsTouch_Flag = true;			
					}
				}
			}
		}

        LimitedArea(obs_x,obs_y);
		if(IsTouch_Flag == true || Limited_Flag == true)
		{
			w++;
		}
		delete ArmXY;
// 		ArmXY = MappingImgToArm(vBolt[w].Get_x(),vBolt[w].Get_y());
// 		obs_x = ArmXY[0];
// 		obs_y = ArmXY[1];
// 		delete ArmXY;
// 		LimitedArea(obs_x,obs_y);
// 		if(Limited_Flag==true)
// 		{
// 			w++;
// 		}
	} while (IsTouch_Flag == true && w < vBolt.size());
}

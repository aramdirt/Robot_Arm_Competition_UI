#ifndef _IA_OBJDEF_H_
#define _IA_OBJDEF_H_

#include <vector>
#include <math.h>
#include "../include/ImageModel/MultiVideoProcessDll_Exports.h"
///////////////////////////////
typedef enum{
	eNut = 0, 
	eBolt, 
	eWasher
}teSelectObjType;
///////////////////////////////
typedef enum{
	eAssortingBolt_Box = 0,
	eAssortingNutWasher_Box,
	eHole_Box,
	ePole_Box,
	eBolt_Box
}teSelectBoxType;
///////////////////////////////
typedef struct WeightMap{
	int WeightofBolt;
	int WeightofNut;
	int WeightofWasher; 
	double dRotation;
}tsWeightMap;
///////////////////////////////
class CObject {
private:

	double x;
	double y;
	double Tf_x;
	double Tf_y;
	double Rotation;
// 	vector<double> vRotation;
// 	int WeightofNut;
// 	int WeightofBolt;
// 	int WeightofWasher;
	int Number;
	int Order;
	teSelectObjType ObjType;

public:

	vector<double> vRotation;
	int WeightofNut;
	int WeightofBolt;
	int WeightofWasher;

	void Set_Position(double a, double b);
	void Set_Tf_Position(double c, double d);
	void Set_Number(int number);
	void Set_Rotation(double rotation);
	void Set_Order(int order);
	void Set_Weight(int weightofnut, int weightofbolt, int weightofwasher);
	void Set_ObjType(teSelectObjType objtype);
	
	double Get_x() {return x; }
	double Get_y() {return y; }
	double Get_Tf_x(){return Tf_x; }
	double Get_Tf_y(){return Tf_y; }
	double Get_Rotation() {return Rotation; }
	int Get_Number(){return Number;}
	int Get_Order() {return Order; }
	int Get_WeightofNut() {return WeightofNut;}
	int Get_WeightofBolt() {return WeightofBolt;}
	int Get_WeightofWasher() {return WeightofWasher;}
	teSelectObjType Get_ObjType() {return ObjType; }
};
class CBox {
private:

	double x;
	double y;
	double Tf_x;
	double Tf_y;
	teSelectBoxType BoxType;

public:

	void Set_Position(double a, double b);
	void Set_Tf_Position(double c, double d);
	void Set_BoxType(teSelectBoxType boxtype);
	
	double Get_x() {return x; }
	double Get_y() {return y; }
	double Get_Tf_x(){return Tf_x; }
	double Get_Tf_y(){return Tf_y; }
	teSelectBoxType Get_BoxType() {return BoxType; }
};
class CObjBox_Info{
private:

	int RemainOf_TotalNut;
	int RemainOf_TotalBolt;
	int RemainOf_AssortNut;
	int RemainOf_AssortBolt;
	int RemainOf_InsertNut;
	int RemainOf_InsertBolt;
	int RemainOf_TightNut;

	vector<ScrewParam> vPreparationBox_Target;
	//vector<tsTargetBox> vTargetBoxInfo;
public:

	//Object_Info();
	//static void IntelAssort_ImageObjInfo(ScrewParam* ImageObjectInfo);
	//void Initialize_Obj();
	void Clean_PreparationBox_Target();
	void Push_PreparationBox_Target(ScrewParam* Target);
	void Sort_PreparationBox_Target(vector<ScrewParam*> vTarget);
	//void Push_TargetBox(tsTargetBox* TargetBoxInfo);
	//int* Sub_RemainMissionObject(Start_Box::Task_Box_Type MissionName);
	//int* RemainMissionObject(Start_Box::Task_Box_Type MissionName);
	
};


//void Get_Coordinate(double r_x, double r_y, double r_rtn);
#endif
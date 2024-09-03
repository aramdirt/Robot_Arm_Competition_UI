#include "stdafx.h"
#include "IA_ObjDef.h"

//============================Obj====================================//
void CObject::Set_Position(double a, double b)
{
	x = a;
	y = b;
}
void CObject::Set_Tf_Position(double c, double d)
{
	Tf_x = c;
	Tf_y = d;
}
void CObject::Set_Rotation(double rotation)
{
	Rotation = rotation;
}
void CObject::Set_Number(int number)
{
	Number = number;
}
void CObject::Set_Order(int order)
{
	Order = order;
}
void CObject::Set_Weight(int weightofnut, int weightofbolt, int weightofwasher)
{
	WeightofNut = weightofnut;
	WeightofBolt = weightofbolt;
	WeightofWasher = weightofwasher;
}
void CObject::Set_ObjType(teSelectObjType objtype)
{
	ObjType = objtype;
}
//==============================Box==================================//
void CBox::Set_Position(double a, double b)
{
	x = a;
	y = b;
}
void CBox::Set_Tf_Position(double c, double d)
{
	Tf_x = c;
	Tf_y = d;
}
void CBox::Set_BoxType(teSelectBoxType boxtype)
{
	BoxType = boxtype;
}
//===================================================================//
void CObjBox_Info::Clean_PreparationBox_Target()
{
	if(!vPreparationBox_Target.empty()) vPreparationBox_Target.clear();
}
void CObjBox_Info::Push_PreparationBox_Target(ScrewParam* Target)
{
	vPreparationBox_Target.push_back(*Target);
}
// void Get_Coordinate(double r_x, double r_y, double r_rtn)
// {
// 	double R_X_Position = r_x;
// 	double R_Y_Position = r_y;
// 	double R_Rotation = r_rtn;
// }

#pragma once

//#include "./stdafx.h"

#include "../MC8881P/FromMC8881P.h"
#include "../MINAS_A5/FormMINAS_A5.h"
#include "../IOCard/FormLeapIO48.h"
#include "../Joystick/FormJoystick.h"
#include "../Joystick/FormArmUI_Joy.h"
#include "../Task_Editor/Form_Task_Editor.h"
#include "../DebugForm.h"

#include "../Task_Editor/TaskExecutor.h"
#include "../Arm/ArmControl.h"
#include "../Arm/Arm.h"
#include "../Arm/ArmDevice.h"
#include "../Gripper/CGripper.h"
#include "../Stra_ObjClassify/Form_ImageModel.h"
#include "../Stra_ObjClassify/Form_Stra_ObjClassify.h"

#include "../Strategy/FormStrategy.h"

#include <direct.h>
//#include "../IA_TestModule/IA_TestModule.h"
#include "IA_ArmMovement.h"
#include "IA_ObjDef.h"
#include "TPerformanceCounterUnit.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>


//extern Get_Coordinate(double r_x, double r_y, double r_rtn, int cnt);

/*void ArmMessage( string &Msg, int iColor );
void CALLBACK fnMainProcessCallback(UINT wTimerID, UINT msg,DWORD dwUser, DWORD dwl,DWORD dw2);*/

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

namespace RobotArm5 {

	/// <summary>
	/// Summary for FormIA
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormIA : public System::Windows::Forms::Form
	{
	public:
		FormIA(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			//Gripper	= new CGripper();
			//Arm = new CArm();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormIA()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Btn_IA_OpenVision;
	private: System::Windows::Forms::Button^  Btn_CameraGoal_R;
	protected: 

	protected: 

	private: System::Windows::Forms::GroupBox^  Position;
	private: System::Windows::Forms::Label^  Pyaw;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  Ppitch;

	private: System::Windows::Forms::Label^  Pz;

	private: System::Windows::Forms::Label^  Py;

	private: System::Windows::Forms::Label^  Px;







	private: System::Windows::Forms::GroupBox^  speed;
	private: System::Windows::Forms::Button^  confirm;
	private: System::Windows::Forms::TextBox^  speedtxt;
	private: System::Windows::Forms::Label^  Svalue;
	private: System::Windows::Forms::GroupBox^  Amove;
	private: System::Windows::Forms::Label^  Aroll;

	private: System::Windows::Forms::Label^  Apitch;

	private: System::Windows::Forms::Label^  Az;

	private: System::Windows::Forms::Label^  Ay;

	private: System::Windows::Forms::Label^  Ax;
	private: System::Windows::Forms::Label^  Ayaw;
	private: System::Windows::Forms::Button^  Aline;



	private: System::Windows::Forms::Button^  APtoP;
	private: System::Windows::Forms::TextBox^  AYawtxt;


	private: System::Windows::Forms::TextBox^  ARolltxt;

	private: System::Windows::Forms::TextBox^  APitchtxt;

	private: System::Windows::Forms::TextBox^  AZtxt;

	private: System::Windows::Forms::TextBox^  AYtxt;

	private: System::Windows::Forms::TextBox^  AXtxt;

	private: System::Windows::Forms::GroupBox^  excute;
	private: System::Windows::Forms::Button^  mission6;


	private: System::Windows::Forms::Button^  mission5;

	private: System::Windows::Forms::Button^  mission4;

	private: System::Windows::Forms::Button^  mission3;
	private: System::Windows::Forms::Button^  mission2;
	private: System::Windows::Forms::Button^  mission1;
	private: System::Windows::Forms::Button^  Estop;
	private: System::Windows::Forms::Button^  Estart;
	private: System::Windows::Forms::GroupBox^  gripper;
	private: System::Windows::Forms::Button^  allopen;
	private: System::Windows::Forms::Button^  close;

	private: System::Windows::Forms::Button^  littleopen;
	private: System::Windows::Forms::Button^  open1;


	private: System::Windows::Forms::GroupBox^  Rmove;
	private: System::Windows::Forms::Button^  RminusZ;

	private: System::Windows::Forms::Button^  RplusZ;

	private: System::Windows::Forms::Button^  RplusX;

	private: System::Windows::Forms::Button^  RplusY;

	private: System::Windows::Forms::Button^  RminusY;
	private: System::Windows::Forms::Button^  RminusX;


	private: System::Windows::Forms::TextBox^  Rvaluetxt;
	private: System::Windows::Forms::Label^  Rvalue;
	private: System::Windows::Forms::Button^  refresh;
	private: System::Windows::Forms::Timer^  timerRefresh;
	private: System::Windows::Forms::Label^  labX;
	private: System::Windows::Forms::Label^  labYaw;

	private: System::Windows::Forms::Label^  labRoll;

	private: System::Windows::Forms::Label^  labPitch;

	private: System::Windows::Forms::Label^  labZ;

	private: System::Windows::Forms::Label^  labY;
	private: System::Windows::Forms::Button^  open2;
	private: System::Windows::Forms::Timer^  timerstart;
	private: System::Windows::Forms::Label^  StatusMotion;


	private: System::Windows::Forms::Label^  StatusMission;


	private: System::Windows::Forms::Label^  ObPositionX;

	private: System::Windows::Forms::GroupBox^  ArmStatus;
	private: System::Windows::Forms::Label^  ObjPosition;

	private: System::Windows::Forms::Label^  Mission;
	private: System::Windows::Forms::Label^  Motion;
	private: System::Windows::Forms::Label^  ObPositionY;
	private: System::Windows::Forms::GroupBox^  ReviseParameter;
	private: System::Windows::Forms::Label^  HeightOfHoleBox;
	private: System::Windows::Forms::Label^  CatchHeight;




	private: System::Windows::Forms::Label^  FastenHeight;



	private: System::Windows::Forms::Label^  PutInNutHeight;

	private: System::Windows::Forms::Label^  ClassifyHeight;
	private: System::Windows::Forms::TextBox^  HeightOfHoleBoxTXT;
	private: System::Windows::Forms::TextBox^  CatchHeightTXT;




	private: System::Windows::Forms::TextBox^  FastenHeightTXT;

	private: System::Windows::Forms::TextBox^  PutInNutHeightTXT;
	private: System::Windows::Forms::TextBox^  ClassfyHeightTXT;
	private: System::Windows::Forms::Button^  StatusComfirm;
private: System::Windows::Forms::Label^  ObPositionZ;













private: System::Windows::Forms::Button^  Btn_CameraGoal_L;
private: System::Windows::Forms::GroupBox^  Coordinate;
private: System::Windows::Forms::Label^  eAssortingBolt_Box_XY;
private: System::Windows::Forms::Label^  eHole_Box_XY;

private: System::Windows::Forms::Label^  eAssortingNutWasher_Box_XY;
private: System::Windows::Forms::Label^  eBolt_Box_XY;
private: System::Windows::Forms::Label^  ePole_Box_XY;
private: System::Windows::Forms::TextBox^  ePole_Box_Y;

private: System::Windows::Forms::TextBox^  ePole_Box_X;

private: System::Windows::Forms::TextBox^  eBolt_Box_Y;

private: System::Windows::Forms::TextBox^  eBolt_Box_X;



private: System::Windows::Forms::TextBox^  eHole_Box_Y;

private: System::Windows::Forms::TextBox^  eHole_Box_X;

private: System::Windows::Forms::TextBox^  eAssortingNutWasher_Box_Y;

private: System::Windows::Forms::TextBox^  eAssortingNutWasher_Box_X;

private: System::Windows::Forms::TextBox^  eAssortingBolt_Box_Y;

private: System::Windows::Forms::TextBox^  eAssortingBolt_Box_X;
private: System::Windows::Forms::Button^  Define_ePole_Box;
private: System::Windows::Forms::Button^  Define_eBolt_Box;




private: System::Windows::Forms::Button^  Define_eHole_Box;

private: System::Windows::Forms::Button^  Define_eAssortingNutWasher_Box;

private: System::Windows::Forms::Button^  Define_eAssortingBolt_Box;
private: System::Windows::Forms::Button^  Confirm_Coordinate;
private: System::Windows::Forms::Label^  StatusTimes;
private: System::Windows::Forms::Button^  mission7;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::TextBox^  txtb_CameraHeight;

private: System::Windows::Forms::Button^  Btn_CameraConfirm;

private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::Button^  ImgTest_Btn;
private: System::Windows::Forms::Timer^  timerImgTest;












































	private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Btn_IA_OpenVision = (gcnew System::Windows::Forms::Button());
			this->Btn_CameraGoal_R = (gcnew System::Windows::Forms::Button());
			this->Position = (gcnew System::Windows::Forms::GroupBox());
			this->labYaw = (gcnew System::Windows::Forms::Label());
			this->labRoll = (gcnew System::Windows::Forms::Label());
			this->labPitch = (gcnew System::Windows::Forms::Label());
			this->labZ = (gcnew System::Windows::Forms::Label());
			this->labY = (gcnew System::Windows::Forms::Label());
			this->labX = (gcnew System::Windows::Forms::Label());
			this->Pyaw = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Ppitch = (gcnew System::Windows::Forms::Label());
			this->Pz = (gcnew System::Windows::Forms::Label());
			this->Py = (gcnew System::Windows::Forms::Label());
			this->Px = (gcnew System::Windows::Forms::Label());
			this->speed = (gcnew System::Windows::Forms::GroupBox());
			this->confirm = (gcnew System::Windows::Forms::Button());
			this->speedtxt = (gcnew System::Windows::Forms::TextBox());
			this->Svalue = (gcnew System::Windows::Forms::Label());
			this->Amove = (gcnew System::Windows::Forms::GroupBox());
			this->refresh = (gcnew System::Windows::Forms::Button());
			this->Aline = (gcnew System::Windows::Forms::Button());
			this->APtoP = (gcnew System::Windows::Forms::Button());
			this->AYawtxt = (gcnew System::Windows::Forms::TextBox());
			this->ARolltxt = (gcnew System::Windows::Forms::TextBox());
			this->APitchtxt = (gcnew System::Windows::Forms::TextBox());
			this->AZtxt = (gcnew System::Windows::Forms::TextBox());
			this->AYtxt = (gcnew System::Windows::Forms::TextBox());
			this->AXtxt = (gcnew System::Windows::Forms::TextBox());
			this->Ayaw = (gcnew System::Windows::Forms::Label());
			this->Aroll = (gcnew System::Windows::Forms::Label());
			this->Apitch = (gcnew System::Windows::Forms::Label());
			this->Az = (gcnew System::Windows::Forms::Label());
			this->Ay = (gcnew System::Windows::Forms::Label());
			this->Ax = (gcnew System::Windows::Forms::Label());
			this->excute = (gcnew System::Windows::Forms::GroupBox());
			this->ImgTest_Btn = (gcnew System::Windows::Forms::Button());
			this->mission6 = (gcnew System::Windows::Forms::Button());
			this->mission7 = (gcnew System::Windows::Forms::Button());
			this->mission5 = (gcnew System::Windows::Forms::Button());
			this->mission4 = (gcnew System::Windows::Forms::Button());
			this->mission3 = (gcnew System::Windows::Forms::Button());
			this->mission2 = (gcnew System::Windows::Forms::Button());
			this->mission1 = (gcnew System::Windows::Forms::Button());
			this->Estop = (gcnew System::Windows::Forms::Button());
			this->Estart = (gcnew System::Windows::Forms::Button());
			this->gripper = (gcnew System::Windows::Forms::GroupBox());
			this->open2 = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::Button());
			this->littleopen = (gcnew System::Windows::Forms::Button());
			this->open1 = (gcnew System::Windows::Forms::Button());
			this->allopen = (gcnew System::Windows::Forms::Button());
			this->Rmove = (gcnew System::Windows::Forms::GroupBox());
			this->RminusZ = (gcnew System::Windows::Forms::Button());
			this->RplusZ = (gcnew System::Windows::Forms::Button());
			this->RplusX = (gcnew System::Windows::Forms::Button());
			this->RplusY = (gcnew System::Windows::Forms::Button());
			this->RminusY = (gcnew System::Windows::Forms::Button());
			this->RminusX = (gcnew System::Windows::Forms::Button());
			this->Rvaluetxt = (gcnew System::Windows::Forms::TextBox());
			this->Rvalue = (gcnew System::Windows::Forms::Label());
			this->timerRefresh = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerstart = (gcnew System::Windows::Forms::Timer(this->components));
			this->StatusMotion = (gcnew System::Windows::Forms::Label());
			this->StatusMission = (gcnew System::Windows::Forms::Label());
			this->ObPositionX = (gcnew System::Windows::Forms::Label());
			this->ArmStatus = (gcnew System::Windows::Forms::GroupBox());
			this->ObPositionZ = (gcnew System::Windows::Forms::Label());
			this->ObPositionY = (gcnew System::Windows::Forms::Label());
			this->ObjPosition = (gcnew System::Windows::Forms::Label());
			this->Mission = (gcnew System::Windows::Forms::Label());
			this->Motion = (gcnew System::Windows::Forms::Label());
			this->StatusTimes = (gcnew System::Windows::Forms::Label());
			this->ReviseParameter = (gcnew System::Windows::Forms::GroupBox());
			this->StatusComfirm = (gcnew System::Windows::Forms::Button());
			this->HeightOfHoleBoxTXT = (gcnew System::Windows::Forms::TextBox());
			this->CatchHeightTXT = (gcnew System::Windows::Forms::TextBox());
			this->FastenHeightTXT = (gcnew System::Windows::Forms::TextBox());
			this->PutInNutHeightTXT = (gcnew System::Windows::Forms::TextBox());
			this->ClassfyHeightTXT = (gcnew System::Windows::Forms::TextBox());
			this->HeightOfHoleBox = (gcnew System::Windows::Forms::Label());
			this->CatchHeight = (gcnew System::Windows::Forms::Label());
			this->FastenHeight = (gcnew System::Windows::Forms::Label());
			this->PutInNutHeight = (gcnew System::Windows::Forms::Label());
			this->ClassifyHeight = (gcnew System::Windows::Forms::Label());
			this->Btn_CameraGoal_L = (gcnew System::Windows::Forms::Button());
			this->Coordinate = (gcnew System::Windows::Forms::GroupBox());
			this->Confirm_Coordinate = (gcnew System::Windows::Forms::Button());
			this->Define_ePole_Box = (gcnew System::Windows::Forms::Button());
			this->Define_eBolt_Box = (gcnew System::Windows::Forms::Button());
			this->Define_eHole_Box = (gcnew System::Windows::Forms::Button());
			this->Define_eAssortingNutWasher_Box = (gcnew System::Windows::Forms::Button());
			this->Define_eAssortingBolt_Box = (gcnew System::Windows::Forms::Button());
			this->ePole_Box_Y = (gcnew System::Windows::Forms::TextBox());
			this->ePole_Box_X = (gcnew System::Windows::Forms::TextBox());
			this->eBolt_Box_Y = (gcnew System::Windows::Forms::TextBox());
			this->eBolt_Box_X = (gcnew System::Windows::Forms::TextBox());
			this->eHole_Box_Y = (gcnew System::Windows::Forms::TextBox());
			this->eHole_Box_X = (gcnew System::Windows::Forms::TextBox());
			this->eAssortingNutWasher_Box_Y = (gcnew System::Windows::Forms::TextBox());
			this->eAssortingNutWasher_Box_X = (gcnew System::Windows::Forms::TextBox());
			this->ePole_Box_XY = (gcnew System::Windows::Forms::Label());
			this->eAssortingBolt_Box_Y = (gcnew System::Windows::Forms::TextBox());
			this->eAssortingBolt_Box_XY = (gcnew System::Windows::Forms::Label());
			this->eAssortingBolt_Box_X = (gcnew System::Windows::Forms::TextBox());
			this->eBolt_Box_XY = (gcnew System::Windows::Forms::Label());
			this->eAssortingNutWasher_Box_XY = (gcnew System::Windows::Forms::Label());
			this->eHole_Box_XY = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->txtb_CameraHeight = (gcnew System::Windows::Forms::TextBox());
			this->Btn_CameraConfirm = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timerImgTest = (gcnew System::Windows::Forms::Timer(this->components));
			this->Position->SuspendLayout();
			this->speed->SuspendLayout();
			this->Amove->SuspendLayout();
			this->excute->SuspendLayout();
			this->gripper->SuspendLayout();
			this->Rmove->SuspendLayout();
			this->ArmStatus->SuspendLayout();
			this->ReviseParameter->SuspendLayout();
			this->Coordinate->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Btn_IA_OpenVision
			// 
			this->Btn_IA_OpenVision->BackColor = System::Drawing::Color::Lavender;
			this->Btn_IA_OpenVision->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Btn_IA_OpenVision->Location = System::Drawing::Point(37, 12);
			this->Btn_IA_OpenVision->Name = L"Btn_IA_OpenVision";
			this->Btn_IA_OpenVision->Size = System::Drawing::Size(99, 91);
			this->Btn_IA_OpenVision->TabIndex = 0;
			this->Btn_IA_OpenVision->Text = L"Open\r\nVision";
			this->Btn_IA_OpenVision->UseVisualStyleBackColor = false;
			this->Btn_IA_OpenVision->Click += gcnew System::EventHandler(this, &FormIA::Btn_IA_OpenVision_Click);
			// 
			// Btn_CameraGoal_R
			// 
			this->Btn_CameraGoal_R->BackColor = System::Drawing::Color::Lavender;
			this->Btn_CameraGoal_R->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Btn_CameraGoal_R->Location = System::Drawing::Point(229, 12);
			this->Btn_CameraGoal_R->Name = L"Btn_CameraGoal_R";
			this->Btn_CameraGoal_R->Size = System::Drawing::Size(81, 91);
			this->Btn_CameraGoal_R->TabIndex = 1;
			this->Btn_CameraGoal_R->Tag = L"0";
			this->Btn_CameraGoal_R->Text = L"Camera\r\nGoal-R";
			this->Btn_CameraGoal_R->UseVisualStyleBackColor = false;
			this->Btn_CameraGoal_R->Click += gcnew System::EventHandler(this, &FormIA::Btn_CameraGoal_Click);
			// 
			// Position
			// 
			this->Position->Controls->Add(this->labYaw);
			this->Position->Controls->Add(this->labRoll);
			this->Position->Controls->Add(this->labPitch);
			this->Position->Controls->Add(this->labZ);
			this->Position->Controls->Add(this->labY);
			this->Position->Controls->Add(this->labX);
			this->Position->Controls->Add(this->Pyaw);
			this->Position->Controls->Add(this->label5);
			this->Position->Controls->Add(this->Ppitch);
			this->Position->Controls->Add(this->Pz);
			this->Position->Controls->Add(this->Py);
			this->Position->Controls->Add(this->Px);
			this->Position->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Position->Location = System::Drawing::Point(37, 127);
			this->Position->Name = L"Position";
			this->Position->Size = System::Drawing::Size(273, 207);
			this->Position->TabIndex = 2;
			this->Position->TabStop = false;
			this->Position->Text = L"Position";
			// 
			// labYaw
			// 
			this->labYaw->AutoSize = true;
			this->labYaw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labYaw->ForeColor = System::Drawing::Color::MediumBlue;
			this->labYaw->Location = System::Drawing::Point(197, 162);
			this->labYaw->Name = L"labYaw";
			this->labYaw->Size = System::Drawing::Size(52, 16);
			this->labYaw->TabIndex = 11;
			this->labYaw->Text = L"999.99";
			// 
			// labRoll
			// 
			this->labRoll->AutoSize = true;
			this->labRoll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labRoll->ForeColor = System::Drawing::Color::MediumBlue;
			this->labRoll->Location = System::Drawing::Point(197, 100);
			this->labRoll->Name = L"labRoll";
			this->labRoll->Size = System::Drawing::Size(52, 16);
			this->labRoll->TabIndex = 10;
			this->labRoll->Text = L"999.99";
			// 
			// labPitch
			// 
			this->labPitch->AutoSize = true;
			this->labPitch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labPitch->ForeColor = System::Drawing::Color::MediumBlue;
			this->labPitch->Location = System::Drawing::Point(197, 36);
			this->labPitch->Name = L"labPitch";
			this->labPitch->Size = System::Drawing::Size(52, 16);
			this->labPitch->TabIndex = 9;
			this->labPitch->Text = L"999.99";
			// 
			// labZ
			// 
			this->labZ->AutoSize = true;
			this->labZ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labZ->ForeColor = System::Drawing::Color::MediumBlue;
			this->labZ->Location = System::Drawing::Point(66, 162);
			this->labZ->Name = L"labZ";
			this->labZ->Size = System::Drawing::Size(60, 16);
			this->labZ->TabIndex = 8;
			this->labZ->Text = L"999.999";
			// 
			// labY
			// 
			this->labY->AutoSize = true;
			this->labY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labY->ForeColor = System::Drawing::Color::MediumBlue;
			this->labY->Location = System::Drawing::Point(66, 100);
			this->labY->Name = L"labY";
			this->labY->Size = System::Drawing::Size(60, 16);
			this->labY->TabIndex = 7;
			this->labY->Text = L"999.999";
			// 
			// labX
			// 
			this->labX->AutoSize = true;
			this->labX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labX->ForeColor = System::Drawing::Color::MediumBlue;
			this->labX->Location = System::Drawing::Point(66, 36);
			this->labX->Name = L"labX";
			this->labX->Size = System::Drawing::Size(60, 16);
			this->labX->TabIndex = 6;
			this->labX->Text = L"999.999";
			// 
			// Pyaw
			// 
			this->Pyaw->AutoSize = true;
			this->Pyaw->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Pyaw->Location = System::Drawing::Point(145, 162);
			this->Pyaw->Name = L"Pyaw";
			this->Pyaw->Size = System::Drawing::Size(40, 18);
			this->Pyaw->TabIndex = 5;
			this->Pyaw->Text = L"Yaw:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(145, 100);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 18);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Roll:";
			// 
			// Ppitch
			// 
			this->Ppitch->AutoSize = true;
			this->Ppitch->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Ppitch->Location = System::Drawing::Point(143, 36);
			this->Ppitch->Name = L"Ppitch";
			this->Ppitch->Size = System::Drawing::Size(56, 18);
			this->Ppitch->TabIndex = 3;
			this->Ppitch->Text = L"Pitch:";
			this->Ppitch->Click += gcnew System::EventHandler(this, &FormIA::Ppitch_Click);
			// 
			// Pz
			// 
			this->Pz->AutoSize = true;
			this->Pz->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Pz->Location = System::Drawing::Point(22, 162);
			this->Pz->Name = L"Pz";
			this->Pz->Size = System::Drawing::Size(40, 18);
			this->Pz->TabIndex = 2;
			this->Pz->Text = L"Z = ";
			// 
			// Py
			// 
			this->Py->AutoSize = true;
			this->Py->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Py->Location = System::Drawing::Point(21, 100);
			this->Py->Name = L"Py";
			this->Py->Size = System::Drawing::Size(40, 18);
			this->Py->TabIndex = 1;
			this->Py->Text = L"Y = ";
			// 
			// Px
			// 
			this->Px->AutoSize = true;
			this->Px->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Px->Location = System::Drawing::Point(21, 36);
			this->Px->Name = L"Px";
			this->Px->Size = System::Drawing::Size(40, 18);
			this->Px->TabIndex = 0;
			this->Px->Text = L"X = ";
			// 
			// speed
			// 
			this->speed->Controls->Add(this->confirm);
			this->speed->Controls->Add(this->speedtxt);
			this->speed->Controls->Add(this->Svalue);
			this->speed->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->speed->Location = System::Drawing::Point(333, 12);
			this->speed->Name = L"speed";
			this->speed->Size = System::Drawing::Size(271, 76);
			this->speed->TabIndex = 4;
			this->speed->TabStop = false;
			this->speed->Text = L"Speed";
			this->speed->Enter += gcnew System::EventHandler(this, &FormIA::speed_Enter);
			// 
			// confirm
			// 
			this->confirm->BackColor = System::Drawing::Color::Thistle;
			this->confirm->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->confirm->Location = System::Drawing::Point(180, 25);
			this->confirm->Name = L"confirm";
			this->confirm->Size = System::Drawing::Size(71, 34);
			this->confirm->TabIndex = 2;
			this->confirm->Text = L"確認";
			this->confirm->UseVisualStyleBackColor = false;
			this->confirm->Click += gcnew System::EventHandler(this, &FormIA::confirm_Click);
			// 
			// speedtxt
			// 
			this->speedtxt->Location = System::Drawing::Point(70, 33);
			this->speedtxt->Name = L"speedtxt";
			this->speedtxt->Size = System::Drawing::Size(90, 25);
			this->speedtxt->TabIndex = 1;
			this->speedtxt->Text = L"20";
			// 
			// Svalue
			// 
			this->Svalue->AutoSize = true;
			this->Svalue->Location = System::Drawing::Point(17, 36);
			this->Svalue->Name = L"Svalue";
			this->Svalue->Size = System::Drawing::Size(51, 17);
			this->Svalue->TabIndex = 0;
			this->Svalue->Text = L"Value:";
			// 
			// Amove
			// 
			this->Amove->Controls->Add(this->refresh);
			this->Amove->Controls->Add(this->Aline);
			this->Amove->Controls->Add(this->APtoP);
			this->Amove->Controls->Add(this->AYawtxt);
			this->Amove->Controls->Add(this->ARolltxt);
			this->Amove->Controls->Add(this->APitchtxt);
			this->Amove->Controls->Add(this->AZtxt);
			this->Amove->Controls->Add(this->AYtxt);
			this->Amove->Controls->Add(this->AXtxt);
			this->Amove->Controls->Add(this->Ayaw);
			this->Amove->Controls->Add(this->Aroll);
			this->Amove->Controls->Add(this->Apitch);
			this->Amove->Controls->Add(this->Az);
			this->Amove->Controls->Add(this->Ay);
			this->Amove->Controls->Add(this->Ax);
			this->Amove->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Amove->Location = System::Drawing::Point(333, 113);
			this->Amove->Name = L"Amove";
			this->Amove->Size = System::Drawing::Size(370, 221);
			this->Amove->TabIndex = 5;
			this->Amove->TabStop = false;
			this->Amove->Text = L"Absolutely Move";
			// 
			// refresh
			// 
			this->refresh->BackColor = System::Drawing::Color::Pink;
			this->refresh->Location = System::Drawing::Point(253, 159);
			this->refresh->Name = L"refresh";
			this->refresh->Size = System::Drawing::Size(101, 49);
			this->refresh->TabIndex = 14;
			this->refresh->Text = L"Refresh";
			this->refresh->UseVisualStyleBackColor = false;
			this->refresh->Click += gcnew System::EventHandler(this, &FormIA::refresh_Click);
			// 
			// Aline
			// 
			this->Aline->BackColor = System::Drawing::Color::Pink;
			this->Aline->Location = System::Drawing::Point(137, 159);
			this->Aline->Name = L"Aline";
			this->Aline->Size = System::Drawing::Size(101, 49);
			this->Aline->TabIndex = 13;
			this->Aline->Text = L"Line";
			this->Aline->UseVisualStyleBackColor = false;
			this->Aline->Click += gcnew System::EventHandler(this, &FormIA::Aline_Click);
			// 
			// APtoP
			// 
			this->APtoP->BackColor = System::Drawing::Color::Pink;
			this->APtoP->Location = System::Drawing::Point(20, 157);
			this->APtoP->Name = L"APtoP";
			this->APtoP->Size = System::Drawing::Size(101, 49);
			this->APtoP->TabIndex = 12;
			this->APtoP->Text = L"P to P";
			this->APtoP->UseVisualStyleBackColor = false;
			this->APtoP->Click += gcnew System::EventHandler(this, &FormIA::APtoP_Click);
			// 
			// AYawtxt
			// 
			this->AYawtxt->Location = System::Drawing::Point(253, 120);
			this->AYawtxt->Name = L"AYawtxt";
			this->AYawtxt->Size = System::Drawing::Size(85, 25);
			this->AYawtxt->TabIndex = 11;
			this->AYawtxt->Text = L"0";
			this->AYawtxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ARolltxt
			// 
			this->ARolltxt->Location = System::Drawing::Point(137, 121);
			this->ARolltxt->Name = L"ARolltxt";
			this->ARolltxt->Size = System::Drawing::Size(85, 25);
			this->ARolltxt->TabIndex = 10;
			this->ARolltxt->Text = L"0";
			this->ARolltxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// APitchtxt
			// 
			this->APitchtxt->Location = System::Drawing::Point(23, 120);
			this->APitchtxt->Name = L"APitchtxt";
			this->APitchtxt->Size = System::Drawing::Size(85, 25);
			this->APitchtxt->TabIndex = 9;
			this->APitchtxt->Text = L"-90";
			this->APitchtxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->APitchtxt->TextChanged += gcnew System::EventHandler(this, &FormIA::APitchtxt_TextChanged);
			// 
			// AZtxt
			// 
			this->AZtxt->Location = System::Drawing::Point(253, 57);
			this->AZtxt->Name = L"AZtxt";
			this->AZtxt->Size = System::Drawing::Size(85, 25);
			this->AZtxt->TabIndex = 8;
			this->AZtxt->Text = L"20";
			this->AZtxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->AZtxt->TextChanged += gcnew System::EventHandler(this, &FormIA::textBox3_TextChanged);
			// 
			// AYtxt
			// 
			this->AYtxt->Location = System::Drawing::Point(137, 57);
			this->AYtxt->Name = L"AYtxt";
			this->AYtxt->Size = System::Drawing::Size(85, 25);
			this->AYtxt->TabIndex = 7;
			this->AYtxt->Text = L"50";
			this->AYtxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AXtxt
			// 
			this->AXtxt->Location = System::Drawing::Point(23, 57);
			this->AXtxt->Name = L"AXtxt";
			this->AXtxt->Size = System::Drawing::Size(85, 25);
			this->AXtxt->TabIndex = 6;
			this->AXtxt->Text = L"0";
			this->AXtxt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Ayaw
			// 
			this->Ayaw->AutoSize = true;
			this->Ayaw->Location = System::Drawing::Point(254, 93);
			this->Ayaw->Name = L"Ayaw";
			this->Ayaw->Size = System::Drawing::Size(40, 17);
			this->Ayaw->TabIndex = 5;
			this->Ayaw->Text = L"Yaw:";
			// 
			// Aroll
			// 
			this->Aroll->AutoSize = true;
			this->Aroll->Location = System::Drawing::Point(134, 93);
			this->Aroll->Name = L"Aroll";
			this->Aroll->Size = System::Drawing::Size(41, 17);
			this->Aroll->TabIndex = 4;
			this->Aroll->Text = L"Roll:";
			// 
			// Apitch
			// 
			this->Apitch->AutoSize = true;
			this->Apitch->Location = System::Drawing::Point(20, 93);
			this->Apitch->Name = L"Apitch";
			this->Apitch->Size = System::Drawing::Size(47, 17);
			this->Apitch->TabIndex = 3;
			this->Apitch->Text = L"Pitch:";
			// 
			// Az
			// 
			this->Az->AutoSize = true;
			this->Az->Location = System::Drawing::Point(254, 31);
			this->Az->Name = L"Az";
			this->Az->Size = System::Drawing::Size(20, 17);
			this->Az->TabIndex = 2;
			this->Az->Text = L"Z:";
			// 
			// Ay
			// 
			this->Ay->AutoSize = true;
			this->Ay->Location = System::Drawing::Point(134, 31);
			this->Ay->Name = L"Ay";
			this->Ay->Size = System::Drawing::Size(20, 17);
			this->Ay->TabIndex = 1;
			this->Ay->Text = L"Y:";
			// 
			// Ax
			// 
			this->Ax->AutoSize = true;
			this->Ax->Location = System::Drawing::Point(20, 31);
			this->Ax->Name = L"Ax";
			this->Ax->Size = System::Drawing::Size(21, 17);
			this->Ax->TabIndex = 0;
			this->Ax->Text = L"X:";
			// 
			// excute
			// 
			this->excute->Controls->Add(this->ImgTest_Btn);
			this->excute->Controls->Add(this->mission6);
			this->excute->Controls->Add(this->mission7);
			this->excute->Controls->Add(this->mission5);
			this->excute->Controls->Add(this->mission4);
			this->excute->Controls->Add(this->mission3);
			this->excute->Controls->Add(this->mission2);
			this->excute->Controls->Add(this->mission1);
			this->excute->Controls->Add(this->Estop);
			this->excute->Controls->Add(this->Estart);
			this->excute->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->excute->Location = System::Drawing::Point(333, 341);
			this->excute->Name = L"excute";
			this->excute->Size = System::Drawing::Size(485, 215);
			this->excute->TabIndex = 6;
			this->excute->TabStop = false;
			this->excute->Text = L"Execute / Calibrate";
			// 
			// ImgTest_Btn
			// 
			this->ImgTest_Btn->BackColor = System::Drawing::Color::NavajoWhite;
			this->ImgTest_Btn->Location = System::Drawing::Point(20, 168);
			this->ImgTest_Btn->Name = L"ImgTest_Btn";
			this->ImgTest_Btn->Size = System::Drawing::Size(87, 40);
			this->ImgTest_Btn->TabIndex = 8;
			this->ImgTest_Btn->Text = L"ImgTest";
			this->ImgTest_Btn->UseVisualStyleBackColor = false;
			this->ImgTest_Btn->Click += gcnew System::EventHandler(this, &FormIA::ImgTest_Btn_Click);
			// 
			// mission6
			// 
			this->mission6->BackColor = System::Drawing::Color::Cornsilk;
			this->mission6->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mission6->Location = System::Drawing::Point(135, 25);
			this->mission6->Name = L"mission6";
			this->mission6->Size = System::Drawing::Size(103, 54);
			this->mission6->TabIndex = 7;
			this->mission6->Text = L"洞洞盒";
			this->mission6->UseVisualStyleBackColor = false;
			this->mission6->Click += gcnew System::EventHandler(this, &FormIA::mission6_Click);
			// 
			// mission7
			// 
			this->mission7->BackColor = System::Drawing::Color::Cornsilk;
			this->mission7->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mission7->Location = System::Drawing::Point(298, 167);
			this->mission7->Name = L"mission7";
			this->mission7->Size = System::Drawing::Size(99, 40);
			this->mission7->TabIndex = 6;
			this->mission7->Text = L"最高高度";
			this->mission7->UseVisualStyleBackColor = false;
			this->mission7->Click += gcnew System::EventHandler(this, &FormIA::mission7_Click);
			// 
			// mission5
			// 
			this->mission5->BackColor = System::Drawing::Color::Cornsilk;
			this->mission5->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mission5->Location = System::Drawing::Point(186, 167);
			this->mission5->Name = L"mission5";
			this->mission5->Size = System::Drawing::Size(106, 40);
			this->mission5->TabIndex = 6;
			this->mission5->Text = L"最低高度";
			this->mission5->UseVisualStyleBackColor = false;
			this->mission5->Click += gcnew System::EventHandler(this, &FormIA::mission5_Click);
			// 
			// mission4
			// 
			this->mission4->BackColor = System::Drawing::Color::Cornsilk;
			this->mission4->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->mission4->Location = System::Drawing::Point(245, 25);
			this->mission4->Name = L"mission4";
			this->mission4->Size = System::Drawing::Size(102, 54);
			this->mission4->TabIndex = 5;
			this->mission4->Text = L"鎖螺帽盒";
			this->mission4->UseVisualStyleBackColor = false;
			this->mission4->Click += gcnew System::EventHandler(this, &FormIA::mission4_Click);
			// 
			// mission3
			// 
			this->mission3->BackColor = System::Drawing::Color::Cornsilk;
			this->mission3->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mission3->Location = System::Drawing::Point(186, 94);
			this->mission3->Name = L"mission3";
			this->mission3->Size = System::Drawing::Size(106, 53);
			this->mission3->TabIndex = 4;
			this->mission3->Text = L"螺帽墊片   分類盒";
			this->mission3->UseVisualStyleBackColor = false;
			this->mission3->Click += gcnew System::EventHandler(this, &FormIA::mission3_Click);
			// 
			// mission2
			// 
			this->mission2->BackColor = System::Drawing::Color::Cornsilk;
			this->mission2->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->mission2->Location = System::Drawing::Point(353, 25);
			this->mission2->Name = L"mission2";
			this->mission2->Size = System::Drawing::Size(100, 54);
			this->mission2->TabIndex = 3;
			this->mission2->Text = L"圓柱盒";
			this->mission2->UseVisualStyleBackColor = false;
			this->mission2->Click += gcnew System::EventHandler(this, &FormIA::mission2_Click);
			// 
			// mission1
			// 
			this->mission1->BackColor = System::Drawing::Color::Cornsilk;
			this->mission1->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->mission1->Location = System::Drawing::Point(298, 94);
			this->mission1->Name = L"mission1";
			this->mission1->Size = System::Drawing::Size(99, 53);
			this->mission1->TabIndex = 2;
			this->mission1->Text = L"螺栓分類盒";
			this->mission1->UseVisualStyleBackColor = false;
			this->mission1->Click += gcnew System::EventHandler(this, &FormIA::mission1_Click);
			// 
			// Estop
			// 
			this->Estop->BackColor = System::Drawing::Color::Khaki;
			this->Estop->Location = System::Drawing::Point(20, 80);
			this->Estop->Name = L"Estop";
			this->Estop->Size = System::Drawing::Size(87, 79);
			this->Estop->TabIndex = 1;
			this->Estop->Text = L"Stop";
			this->Estop->UseVisualStyleBackColor = false;
			this->Estop->Click += gcnew System::EventHandler(this, &FormIA::Estop_Click);
			// 
			// Estart
			// 
			this->Estart->BackColor = System::Drawing::Color::Khaki;
			this->Estart->Location = System::Drawing::Point(20, 24);
			this->Estart->Name = L"Estart";
			this->Estart->Size = System::Drawing::Size(87, 50);
			this->Estart->TabIndex = 0;
			this->Estart->Text = L"Start";
			this->Estart->UseVisualStyleBackColor = false;
			this->Estart->Click += gcnew System::EventHandler(this, &FormIA::Estart_Click);
			// 
			// gripper
			// 
			this->gripper->Controls->Add(this->open2);
			this->gripper->Controls->Add(this->close);
			this->gripper->Controls->Add(this->littleopen);
			this->gripper->Controls->Add(this->open1);
			this->gripper->Controls->Add(this->allopen);
			this->gripper->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gripper->Location = System::Drawing::Point(615, 12);
			this->gripper->Name = L"gripper";
			this->gripper->Size = System::Drawing::Size(461, 76);
			this->gripper->TabIndex = 7;
			this->gripper->TabStop = false;
			this->gripper->Text = L"Gripper";
			// 
			// open2
			// 
			this->open2->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->open2->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->open2->Location = System::Drawing::Point(196, 23);
			this->open2->Name = L"open2";
			this->open2->Size = System::Drawing::Size(79, 42);
			this->open2->TabIndex = 4;
			this->open2->Text = L"寬度2";
			this->open2->UseVisualStyleBackColor = false;
			this->open2->Click += gcnew System::EventHandler(this, &FormIA::open2_Click);
			// 
			// close
			// 
			this->close->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->close->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->close->Location = System::Drawing::Point(371, 23);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(79, 42);
			this->close->TabIndex = 3;
			this->close->Text = L"夾緊";
			this->close->UseVisualStyleBackColor = false;
			this->close->Click += gcnew System::EventHandler(this, &FormIA::close_Click);
			// 
			// littleopen
			// 
			this->littleopen->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->littleopen->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->littleopen->Location = System::Drawing::Point(283, 23);
			this->littleopen->Name = L"littleopen";
			this->littleopen->Size = System::Drawing::Size(79, 42);
			this->littleopen->TabIndex = 2;
			this->littleopen->Text = L"鬆開";
			this->littleopen->UseVisualStyleBackColor = false;
			this->littleopen->Click += gcnew System::EventHandler(this, &FormIA::littleopen_Click);
			// 
			// open1
			// 
			this->open1->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->open1->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->open1->Location = System::Drawing::Point(107, 23);
			this->open1->Name = L"open1";
			this->open1->Size = System::Drawing::Size(79, 42);
			this->open1->TabIndex = 1;
			this->open1->Text = L"寬度1";
			this->open1->UseVisualStyleBackColor = false;
			this->open1->Click += gcnew System::EventHandler(this, &FormIA::open1_Click);
			// 
			// allopen
			// 
			this->allopen->BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->allopen->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->allopen->Location = System::Drawing::Point(16, 23);
			this->allopen->Name = L"allopen";
			this->allopen->Size = System::Drawing::Size(79, 42);
			this->allopen->TabIndex = 0;
			this->allopen->Text = L"全開";
			this->allopen->UseVisualStyleBackColor = false;
			this->allopen->Click += gcnew System::EventHandler(this, &FormIA::allopen_Click);
			// 
			// Rmove
			// 
			this->Rmove->Controls->Add(this->RminusZ);
			this->Rmove->Controls->Add(this->RplusZ);
			this->Rmove->Controls->Add(this->RplusX);
			this->Rmove->Controls->Add(this->RplusY);
			this->Rmove->Controls->Add(this->RminusY);
			this->Rmove->Controls->Add(this->RminusX);
			this->Rmove->Controls->Add(this->Rvaluetxt);
			this->Rmove->Controls->Add(this->Rvalue);
			this->Rmove->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Rmove->Location = System::Drawing::Point(722, 113);
			this->Rmove->Name = L"Rmove";
			this->Rmove->Size = System::Drawing::Size(354, 221);
			this->Rmove->TabIndex = 8;
			this->Rmove->TabStop = false;
			this->Rmove->Text = L"Relative Move";
			// 
			// RminusZ
			// 
			this->RminusZ->BackColor = System::Drawing::Color::Pink;
			this->RminusZ->Location = System::Drawing::Point(42, 158);
			this->RminusZ->Name = L"RminusZ";
			this->RminusZ->Size = System::Drawing::Size(54, 45);
			this->RminusZ->TabIndex = 7;
			this->RminusZ->Tag = L"-3";
			this->RminusZ->Text = L"-Z";
			this->RminusZ->UseVisualStyleBackColor = false;
			this->RminusZ->Click += gcnew System::EventHandler(this, &FormIA::RminusZ_Click);
			// 
			// RplusZ
			// 
			this->RplusZ->BackColor = System::Drawing::Color::Pink;
			this->RplusZ->Location = System::Drawing::Point(42, 96);
			this->RplusZ->Name = L"RplusZ";
			this->RplusZ->Size = System::Drawing::Size(54, 45);
			this->RplusZ->TabIndex = 6;
			this->RplusZ->Tag = L"3";
			this->RplusZ->Text = L"+Z";
			this->RplusZ->UseVisualStyleBackColor = false;
			this->RplusZ->Click += gcnew System::EventHandler(this, &FormIA::RplusZ_Click);
			// 
			// RplusX
			// 
			this->RplusX->BackColor = System::Drawing::Color::Pink;
			this->RplusX->Location = System::Drawing::Point(271, 158);
			this->RplusX->Name = L"RplusX";
			this->RplusX->Size = System::Drawing::Size(54, 45);
			this->RplusX->TabIndex = 5;
			this->RplusX->Tag = L"1";
			this->RplusX->Text = L"+X";
			this->RplusX->UseVisualStyleBackColor = false;
			this->RplusX->Click += gcnew System::EventHandler(this, &FormIA::RplusX_Click);
			// 
			// RplusY
			// 
			this->RplusY->BackColor = System::Drawing::Color::Pink;
			this->RplusY->Location = System::Drawing::Point(202, 96);
			this->RplusY->Name = L"RplusY";
			this->RplusY->Size = System::Drawing::Size(54, 45);
			this->RplusY->TabIndex = 4;
			this->RplusY->Tag = L"2";
			this->RplusY->Text = L"+Y";
			this->RplusY->UseVisualStyleBackColor = false;
			this->RplusY->Click += gcnew System::EventHandler(this, &FormIA::RplusY_Click);
			// 
			// RminusY
			// 
			this->RminusY->BackColor = System::Drawing::Color::Pink;
			this->RminusY->Location = System::Drawing::Point(202, 158);
			this->RminusY->Name = L"RminusY";
			this->RminusY->Size = System::Drawing::Size(54, 45);
			this->RminusY->TabIndex = 3;
			this->RminusY->Tag = L"-2";
			this->RminusY->Text = L"-Y";
			this->RminusY->UseVisualStyleBackColor = false;
			this->RminusY->Click += gcnew System::EventHandler(this, &FormIA::RminusY_Click);
			// 
			// RminusX
			// 
			this->RminusX->BackColor = System::Drawing::Color::Pink;
			this->RminusX->Location = System::Drawing::Point(132, 158);
			this->RminusX->Name = L"RminusX";
			this->RminusX->Size = System::Drawing::Size(54, 45);
			this->RminusX->TabIndex = 2;
			this->RminusX->Tag = L"-1";
			this->RminusX->Text = L"-X";
			this->RminusX->UseVisualStyleBackColor = false;
			this->RminusX->Click += gcnew System::EventHandler(this, &FormIA::RminusX_Click);
			// 
			// Rvaluetxt
			// 
			this->Rvaluetxt->Location = System::Drawing::Point(176, 40);
			this->Rvaluetxt->Name = L"Rvaluetxt";
			this->Rvaluetxt->Size = System::Drawing::Size(123, 25);
			this->Rvaluetxt->TabIndex = 1;
			this->Rvaluetxt->Text = L"0";
			// 
			// Rvalue
			// 
			this->Rvalue->AutoSize = true;
			this->Rvalue->Location = System::Drawing::Point(26, 43);
			this->Rvalue->Name = L"Rvalue";
			this->Rvalue->Size = System::Drawing::Size(140, 17);
			this->Rvalue->TabIndex = 0;
			this->Rvalue->Text = L"Value(Centimeter):\r\n";
			// 
			// timerRefresh
			// 
			this->timerRefresh->Tick += gcnew System::EventHandler(this, &FormIA::timerRefresh_Tick);
			// 
			// timerstart
			// 
			this->timerstart->Tick += gcnew System::EventHandler(this, &FormIA::timerstart_Tick);
			// 
			// StatusMotion
			// 
			this->StatusMotion->AutoSize = true;
			this->StatusMotion->Font = (gcnew System::Drawing::Font(L"Consolas", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->StatusMotion->ForeColor = System::Drawing::Color::BlueViolet;
			this->StatusMotion->Location = System::Drawing::Point(212, 69);
			this->StatusMotion->Name = L"StatusMotion";
			this->StatusMotion->Size = System::Drawing::Size(18, 19);
			this->StatusMotion->TabIndex = 9;
			this->StatusMotion->Text = L"0";
			// 
			// StatusMission
			// 
			this->StatusMission->AutoSize = true;
			this->StatusMission->Font = (gcnew System::Drawing::Font(L"Consolas", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->StatusMission->ForeColor = System::Drawing::Color::BlueViolet;
			this->StatusMission->Location = System::Drawing::Point(122, 39);
			this->StatusMission->Name = L"StatusMission";
			this->StatusMission->Size = System::Drawing::Size(36, 19);
			this->StatusMission->TabIndex = 10;
			this->StatusMission->Text = L"XXX";
			// 
			// ObPositionX
			// 
			this->ObPositionX->AutoSize = true;
			this->ObPositionX->Font = (gcnew System::Drawing::Font(L"Consolas", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ObPositionX->ForeColor = System::Drawing::Color::BlueViolet;
			this->ObPositionX->Location = System::Drawing::Point(131, 104);
			this->ObPositionX->Name = L"ObPositionX";
			this->ObPositionX->Size = System::Drawing::Size(18, 19);
			this->ObPositionX->TabIndex = 11;
			this->ObPositionX->Text = L"X";
			// 
			// ArmStatus
			// 
			this->ArmStatus->Controls->Add(this->ObPositionZ);
			this->ArmStatus->Controls->Add(this->ObPositionY);
			this->ArmStatus->Controls->Add(this->ObjPosition);
			this->ArmStatus->Controls->Add(this->Mission);
			this->ArmStatus->Controls->Add(this->Motion);
			this->ArmStatus->Controls->Add(this->StatusTimes);
			this->ArmStatus->Controls->Add(this->StatusMotion);
			this->ArmStatus->Controls->Add(this->ObPositionX);
			this->ArmStatus->Controls->Add(this->StatusMission);
			this->ArmStatus->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ArmStatus->Location = System::Drawing::Point(37, 341);
			this->ArmStatus->Margin = System::Windows::Forms::Padding(2);
			this->ArmStatus->Name = L"ArmStatus";
			this->ArmStatus->Padding = System::Windows::Forms::Padding(2);
			this->ArmStatus->Size = System::Drawing::Size(273, 146);
			this->ArmStatus->TabIndex = 12;
			this->ArmStatus->TabStop = false;
			this->ArmStatus->Text = L"Arm Status";
			// 
			// ObPositionZ
			// 
			this->ObPositionZ->AutoSize = true;
			this->ObPositionZ->Font = (gcnew System::Drawing::Font(L"Consolas", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ObPositionZ->ForeColor = System::Drawing::Color::BlueViolet;
			this->ObPositionZ->Location = System::Drawing::Point(212, 104);
			this->ObPositionZ->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ObPositionZ->Name = L"ObPositionZ";
			this->ObPositionZ->Size = System::Drawing::Size(18, 19);
			this->ObPositionZ->TabIndex = 16;
			this->ObPositionZ->Text = L"Z";
			// 
			// ObPositionY
			// 
			this->ObPositionY->AutoSize = true;
			this->ObPositionY->Font = (gcnew System::Drawing::Font(L"Consolas", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ObPositionY->ForeColor = System::Drawing::Color::BlueViolet;
			this->ObPositionY->Location = System::Drawing::Point(175, 104);
			this->ObPositionY->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ObPositionY->Name = L"ObPositionY";
			this->ObPositionY->Size = System::Drawing::Size(18, 19);
			this->ObPositionY->TabIndex = 15;
			this->ObPositionY->Text = L"Y";
			// 
			// ObjPosition
			// 
			this->ObjPosition->AutoSize = true;
			this->ObjPosition->Location = System::Drawing::Point(2, 105);
			this->ObjPosition->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ObjPosition->Name = L"ObjPosition";
			this->ObjPosition->Size = System::Drawing::Size(94, 17);
			this->ObjPosition->TabIndex = 14;
			this->ObjPosition->Text = L"ObjPosition:";
			// 
			// Mission
			// 
			this->Mission->AutoSize = true;
			this->Mission->Location = System::Drawing::Point(32, 38);
			this->Mission->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Mission->Name = L"Mission";
			this->Mission->Size = System::Drawing::Size(67, 17);
			this->Mission->TabIndex = 13;
			this->Mission->Text = L"Mission:";
			// 
			// Motion
			// 
			this->Motion->AutoSize = true;
			this->Motion->Location = System::Drawing::Point(37, 70);
			this->Motion->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Motion->Name = L"Motion";
			this->Motion->Size = System::Drawing::Size(62, 17);
			this->Motion->TabIndex = 12;
			this->Motion->Text = L"Motion:";
			// 
			// StatusTimes
			// 
			this->StatusTimes->AutoSize = true;
			this->StatusTimes->Font = (gcnew System::Drawing::Font(L"Consolas", 12, static_cast<System::Drawing::FontStyle>(((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic) 
				| System::Drawing::FontStyle::Underline)), System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->StatusTimes->ForeColor = System::Drawing::Color::BlueViolet;
			this->StatusTimes->Location = System::Drawing::Point(131, 69);
			this->StatusTimes->Name = L"StatusTimes";
			this->StatusTimes->Size = System::Drawing::Size(18, 19);
			this->StatusTimes->TabIndex = 9;
			this->StatusTimes->Text = L"0";
			// 
			// ReviseParameter
			// 
			this->ReviseParameter->Controls->Add(this->StatusComfirm);
			this->ReviseParameter->Controls->Add(this->HeightOfHoleBoxTXT);
			this->ReviseParameter->Controls->Add(this->CatchHeightTXT);
			this->ReviseParameter->Controls->Add(this->FastenHeightTXT);
			this->ReviseParameter->Controls->Add(this->PutInNutHeightTXT);
			this->ReviseParameter->Controls->Add(this->ClassfyHeightTXT);
			this->ReviseParameter->Controls->Add(this->HeightOfHoleBox);
			this->ReviseParameter->Controls->Add(this->CatchHeight);
			this->ReviseParameter->Controls->Add(this->FastenHeight);
			this->ReviseParameter->Controls->Add(this->PutInNutHeight);
			this->ReviseParameter->Controls->Add(this->ClassifyHeight);
			this->ReviseParameter->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ReviseParameter->Location = System::Drawing::Point(1091, 12);
			this->ReviseParameter->Margin = System::Windows::Forms::Padding(2);
			this->ReviseParameter->Name = L"ReviseParameter";
			this->ReviseParameter->Padding = System::Windows::Forms::Padding(2);
			this->ReviseParameter->Size = System::Drawing::Size(252, 278);
			this->ReviseParameter->TabIndex = 13;
			this->ReviseParameter->TabStop = false;
			this->ReviseParameter->Text = L"ReviseParameter";
			this->ReviseParameter->Enter += gcnew System::EventHandler(this, &FormIA::ReviseParameter_Enter);
			// 
			// StatusComfirm
			// 
			this->StatusComfirm->BackColor = System::Drawing::Color::Cornsilk;
			this->StatusComfirm->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->StatusComfirm->ForeColor = System::Drawing::SystemColors::ControlText;
			this->StatusComfirm->Location = System::Drawing::Point(56, 233);
			this->StatusComfirm->Margin = System::Windows::Forms::Padding(2);
			this->StatusComfirm->Name = L"StatusComfirm";
			this->StatusComfirm->Size = System::Drawing::Size(139, 29);
			this->StatusComfirm->TabIndex = 10;
			this->StatusComfirm->Text = L"確認";
			this->StatusComfirm->UseVisualStyleBackColor = false;
			this->StatusComfirm->Click += gcnew System::EventHandler(this, &FormIA::StatusComfirm_Click);
			// 
			// HeightOfHoleBoxTXT
			// 
			this->HeightOfHoleBoxTXT->Location = System::Drawing::Point(133, 111);
			this->HeightOfHoleBoxTXT->Margin = System::Windows::Forms::Padding(2);
			this->HeightOfHoleBoxTXT->Name = L"HeightOfHoleBoxTXT";
			this->HeightOfHoleBoxTXT->Size = System::Drawing::Size(96, 25);
			this->HeightOfHoleBoxTXT->TabIndex = 9;
			this->HeightOfHoleBoxTXT->Text = L"10";
			this->HeightOfHoleBoxTXT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// CatchHeightTXT
			// 
			this->CatchHeightTXT->Location = System::Drawing::Point(133, 190);
			this->CatchHeightTXT->Margin = System::Windows::Forms::Padding(2);
			this->CatchHeightTXT->Name = L"CatchHeightTXT";
			this->CatchHeightTXT->Size = System::Drawing::Size(96, 25);
			this->CatchHeightTXT->TabIndex = 8;
			this->CatchHeightTXT->Text = L"10";
			this->CatchHeightTXT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// FastenHeightTXT
			// 
			this->FastenHeightTXT->Location = System::Drawing::Point(133, 71);
			this->FastenHeightTXT->Margin = System::Windows::Forms::Padding(2);
			this->FastenHeightTXT->Name = L"FastenHeightTXT";
			this->FastenHeightTXT->Size = System::Drawing::Size(96, 25);
			this->FastenHeightTXT->TabIndex = 7;
			this->FastenHeightTXT->Text = L"10";
			this->FastenHeightTXT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// PutInNutHeightTXT
			// 
			this->PutInNutHeightTXT->Location = System::Drawing::Point(133, 29);
			this->PutInNutHeightTXT->Margin = System::Windows::Forms::Padding(2);
			this->PutInNutHeightTXT->Name = L"PutInNutHeightTXT";
			this->PutInNutHeightTXT->Size = System::Drawing::Size(96, 25);
			this->PutInNutHeightTXT->TabIndex = 6;
			this->PutInNutHeightTXT->Text = L"10";
			this->PutInNutHeightTXT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ClassfyHeightTXT
			// 
			this->ClassfyHeightTXT->Location = System::Drawing::Point(133, 151);
			this->ClassfyHeightTXT->Margin = System::Windows::Forms::Padding(2);
			this->ClassfyHeightTXT->Name = L"ClassfyHeightTXT";
			this->ClassfyHeightTXT->Size = System::Drawing::Size(96, 25);
			this->ClassfyHeightTXT->TabIndex = 5;
			this->ClassfyHeightTXT->Text = L"10";
			this->ClassfyHeightTXT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// HeightOfHoleBox
			// 
			this->HeightOfHoleBox->AutoSize = true;
			this->HeightOfHoleBox->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->HeightOfHoleBox->Location = System::Drawing::Point(19, 116);
			this->HeightOfHoleBox->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->HeightOfHoleBox->Name = L"HeightOfHoleBox";
			this->HeightOfHoleBox->Size = System::Drawing::Size(101, 15);
			this->HeightOfHoleBox->TabIndex = 4;
			this->HeightOfHoleBox->Text = L"洞洞盒高度:";
			// 
			// CatchHeight
			// 
			this->CatchHeight->AutoSize = true;
			this->CatchHeight->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CatchHeight->Location = System::Drawing::Point(36, 195);
			this->CatchHeight->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->CatchHeight->Name = L"CatchHeight";
			this->CatchHeight->Size = System::Drawing::Size(84, 15);
			this->CatchHeight->TabIndex = 3;
			this->CatchHeight->Text = L"夾取高度:";
			// 
			// FastenHeight
			// 
			this->FastenHeight->AutoSize = true;
			this->FastenHeight->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FastenHeight->Location = System::Drawing::Point(2, 76);
			this->FastenHeight->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->FastenHeight->Name = L"FastenHeight";
			this->FastenHeight->Size = System::Drawing::Size(118, 15);
			this->FastenHeight->TabIndex = 2;
			this->FastenHeight->Text = L"鎖螺帽盒高度:";
			// 
			// PutInNutHeight
			// 
			this->PutInNutHeight->AutoSize = true;
			this->PutInNutHeight->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PutInNutHeight->Location = System::Drawing::Point(18, 34);
			this->PutInNutHeight->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->PutInNutHeight->Name = L"PutInNutHeight";
			this->PutInNutHeight->Size = System::Drawing::Size(101, 15);
			this->PutInNutHeight->TabIndex = 1;
			this->PutInNutHeight->Text = L"圓柱盒高度:\r\n";
			// 
			// ClassifyHeight
			// 
			this->ClassifyHeight->AutoSize = true;
			this->ClassifyHeight->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ClassifyHeight->Location = System::Drawing::Point(20, 154);
			this->ClassifyHeight->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ClassifyHeight->Name = L"ClassifyHeight";
			this->ClassifyHeight->Size = System::Drawing::Size(101, 15);
			this->ClassifyHeight->TabIndex = 0;
			this->ClassifyHeight->Text = L"分類盒高度:";
			// 
			// Btn_CameraGoal_L
			// 
			this->Btn_CameraGoal_L->BackColor = System::Drawing::Color::Lavender;
			this->Btn_CameraGoal_L->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Btn_CameraGoal_L->Location = System::Drawing::Point(142, 12);
			this->Btn_CameraGoal_L->Name = L"Btn_CameraGoal_L";
			this->Btn_CameraGoal_L->Size = System::Drawing::Size(82, 91);
			this->Btn_CameraGoal_L->TabIndex = 1;
			this->Btn_CameraGoal_L->Tag = L"1";
			this->Btn_CameraGoal_L->Text = L"Camera\r\nGoal-L";
			this->Btn_CameraGoal_L->UseVisualStyleBackColor = false;
			this->Btn_CameraGoal_L->Click += gcnew System::EventHandler(this, &FormIA::Btn_CameraGoal_Click);
			// 
			// Coordinate
			// 
			this->Coordinate->Controls->Add(this->Confirm_Coordinate);
			this->Coordinate->Controls->Add(this->Define_ePole_Box);
			this->Coordinate->Controls->Add(this->Define_eBolt_Box);
			this->Coordinate->Controls->Add(this->Define_eHole_Box);
			this->Coordinate->Controls->Add(this->Define_eAssortingNutWasher_Box);
			this->Coordinate->Controls->Add(this->Define_eAssortingBolt_Box);
			this->Coordinate->Controls->Add(this->ePole_Box_Y);
			this->Coordinate->Controls->Add(this->ePole_Box_X);
			this->Coordinate->Controls->Add(this->eBolt_Box_Y);
			this->Coordinate->Controls->Add(this->eBolt_Box_X);
			this->Coordinate->Controls->Add(this->eHole_Box_Y);
			this->Coordinate->Controls->Add(this->eHole_Box_X);
			this->Coordinate->Controls->Add(this->eAssortingNutWasher_Box_Y);
			this->Coordinate->Controls->Add(this->eAssortingNutWasher_Box_X);
			this->Coordinate->Controls->Add(this->ePole_Box_XY);
			this->Coordinate->Controls->Add(this->eAssortingBolt_Box_Y);
			this->Coordinate->Controls->Add(this->eAssortingBolt_Box_XY);
			this->Coordinate->Controls->Add(this->eAssortingBolt_Box_X);
			this->Coordinate->Controls->Add(this->eBolt_Box_XY);
			this->Coordinate->Controls->Add(this->eAssortingNutWasher_Box_XY);
			this->Coordinate->Controls->Add(this->eHole_Box_XY);
			this->Coordinate->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Coordinate->Location = System::Drawing::Point(1091, 310);
			this->Coordinate->Name = L"Coordinate";
			this->Coordinate->Size = System::Drawing::Size(334, 246);
			this->Coordinate->TabIndex = 14;
			this->Coordinate->TabStop = false;
			this->Coordinate->Text = L"Coordinate";
			// 
			// Confirm_Coordinate
			// 
			this->Confirm_Coordinate->BackColor = System::Drawing::Color::Cornsilk;
			this->Confirm_Coordinate->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Confirm_Coordinate->Location = System::Drawing::Point(110, 200);
			this->Confirm_Coordinate->Name = L"Confirm_Coordinate";
			this->Confirm_Coordinate->Size = System::Drawing::Size(141, 30);
			this->Confirm_Coordinate->TabIndex = 24;
			this->Confirm_Coordinate->Text = L"確認";
			this->Confirm_Coordinate->UseVisualStyleBackColor = false;
			this->Confirm_Coordinate->Click += gcnew System::EventHandler(this, &FormIA::Confirm_Coordinate_Click);
			// 
			// Define_ePole_Box
			// 
			this->Define_ePole_Box->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Define_ePole_Box->Location = System::Drawing::Point(263, 21);
			this->Define_ePole_Box->Name = L"Define_ePole_Box";
			this->Define_ePole_Box->Size = System::Drawing::Size(54, 22);
			this->Define_ePole_Box->TabIndex = 23;
			this->Define_ePole_Box->Text = L"定位";
			this->Define_ePole_Box->UseVisualStyleBackColor = true;
			this->Define_ePole_Box->Click += gcnew System::EventHandler(this, &FormIA::Define_ePole_Box_Click);
			// 
			// Define_eBolt_Box
			// 
			this->Define_eBolt_Box->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Define_eBolt_Box->Location = System::Drawing::Point(263, 56);
			this->Define_eBolt_Box->Name = L"Define_eBolt_Box";
			this->Define_eBolt_Box->Size = System::Drawing::Size(54, 22);
			this->Define_eBolt_Box->TabIndex = 22;
			this->Define_eBolt_Box->Text = L"定位";
			this->Define_eBolt_Box->UseVisualStyleBackColor = true;
			this->Define_eBolt_Box->Click += gcnew System::EventHandler(this, &FormIA::Define_eBolt_Box_Click_1);
			// 
			// Define_eHole_Box
			// 
			this->Define_eHole_Box->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Define_eHole_Box->Location = System::Drawing::Point(264, 89);
			this->Define_eHole_Box->Name = L"Define_eHole_Box";
			this->Define_eHole_Box->Size = System::Drawing::Size(54, 22);
			this->Define_eHole_Box->TabIndex = 21;
			this->Define_eHole_Box->Text = L"定位";
			this->Define_eHole_Box->UseVisualStyleBackColor = true;
			this->Define_eHole_Box->Click += gcnew System::EventHandler(this, &FormIA::Define_eHole_Box_Click);
			// 
			// Define_eAssortingNutWasher_Box
			// 
			this->Define_eAssortingNutWasher_Box->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Define_eAssortingNutWasher_Box->Location = System::Drawing::Point(263, 160);
			this->Define_eAssortingNutWasher_Box->Name = L"Define_eAssortingNutWasher_Box";
			this->Define_eAssortingNutWasher_Box->Size = System::Drawing::Size(54, 22);
			this->Define_eAssortingNutWasher_Box->TabIndex = 20;
			this->Define_eAssortingNutWasher_Box->Text = L"定位";
			this->Define_eAssortingNutWasher_Box->UseVisualStyleBackColor = true;
			this->Define_eAssortingNutWasher_Box->Click += gcnew System::EventHandler(this, &FormIA::Define_eAssortingNutWasher_Box_Click);
			// 
			// Define_eAssortingBolt_Box
			// 
			this->Define_eAssortingBolt_Box->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Define_eAssortingBolt_Box->Location = System::Drawing::Point(263, 122);
			this->Define_eAssortingBolt_Box->Name = L"Define_eAssortingBolt_Box";
			this->Define_eAssortingBolt_Box->Size = System::Drawing::Size(54, 22);
			this->Define_eAssortingBolt_Box->TabIndex = 19;
			this->Define_eAssortingBolt_Box->Text = L"定位";
			this->Define_eAssortingBolt_Box->UseVisualStyleBackColor = true;
			this->Define_eAssortingBolt_Box->Click += gcnew System::EventHandler(this, &FormIA::Define_eAssortingBolt_Box_Click);
			// 
			// ePole_Box_Y
			// 
			this->ePole_Box_Y->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ePole_Box_Y->Location = System::Drawing::Point(193, 22);
			this->ePole_Box_Y->Margin = System::Windows::Forms::Padding(2);
			this->ePole_Box_Y->Name = L"ePole_Box_Y";
			this->ePole_Box_Y->Size = System::Drawing::Size(58, 23);
			this->ePole_Box_Y->TabIndex = 18;
			this->ePole_Box_Y->Text = L"76.5";
			this->ePole_Box_Y->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ePole_Box_X
			// 
			this->ePole_Box_X->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ePole_Box_X->Location = System::Drawing::Point(124, 22);
			this->ePole_Box_X->Margin = System::Windows::Forms::Padding(2);
			this->ePole_Box_X->Name = L"ePole_Box_X";
			this->ePole_Box_X->Size = System::Drawing::Size(58, 23);
			this->ePole_Box_X->TabIndex = 17;
			this->ePole_Box_X->Text = L"-30";
			this->ePole_Box_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// eBolt_Box_Y
			// 
			this->eBolt_Box_Y->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eBolt_Box_Y->Location = System::Drawing::Point(193, 58);
			this->eBolt_Box_Y->Margin = System::Windows::Forms::Padding(2);
			this->eBolt_Box_Y->Name = L"eBolt_Box_Y";
			this->eBolt_Box_Y->Size = System::Drawing::Size(58, 23);
			this->eBolt_Box_Y->TabIndex = 16;
			this->eBolt_Box_Y->Text = L"62.5";
			this->eBolt_Box_Y->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// eBolt_Box_X
			// 
			this->eBolt_Box_X->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eBolt_Box_X->Location = System::Drawing::Point(124, 58);
			this->eBolt_Box_X->Margin = System::Windows::Forms::Padding(2);
			this->eBolt_Box_X->Name = L"eBolt_Box_X";
			this->eBolt_Box_X->Size = System::Drawing::Size(58, 23);
			this->eBolt_Box_X->TabIndex = 15;
			this->eBolt_Box_X->Text = L"-30";
			this->eBolt_Box_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// eHole_Box_Y
			// 
			this->eHole_Box_Y->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eHole_Box_Y->Location = System::Drawing::Point(193, 90);
			this->eHole_Box_Y->Margin = System::Windows::Forms::Padding(2);
			this->eHole_Box_Y->Name = L"eHole_Box_Y";
			this->eHole_Box_Y->Size = System::Drawing::Size(58, 23);
			this->eHole_Box_Y->TabIndex = 14;
			this->eHole_Box_Y->Text = L"48.5";
			this->eHole_Box_Y->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// eHole_Box_X
			// 
			this->eHole_Box_X->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eHole_Box_X->Location = System::Drawing::Point(124, 90);
			this->eHole_Box_X->Margin = System::Windows::Forms::Padding(2);
			this->eHole_Box_X->Name = L"eHole_Box_X";
			this->eHole_Box_X->Size = System::Drawing::Size(58, 23);
			this->eHole_Box_X->TabIndex = 13;
			this->eHole_Box_X->Text = L"-30";
			this->eHole_Box_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// eAssortingNutWasher_Box_Y
			// 
			this->eAssortingNutWasher_Box_Y->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eAssortingNutWasher_Box_Y->Location = System::Drawing::Point(193, 162);
			this->eAssortingNutWasher_Box_Y->Margin = System::Windows::Forms::Padding(2);
			this->eAssortingNutWasher_Box_Y->Name = L"eAssortingNutWasher_Box_Y";
			this->eAssortingNutWasher_Box_Y->Size = System::Drawing::Size(58, 23);
			this->eAssortingNutWasher_Box_Y->TabIndex = 12;
			this->eAssortingNutWasher_Box_Y->Text = L"55.3";
			this->eAssortingNutWasher_Box_Y->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// eAssortingNutWasher_Box_X
			// 
			this->eAssortingNutWasher_Box_X->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eAssortingNutWasher_Box_X->Location = System::Drawing::Point(124, 162);
			this->eAssortingNutWasher_Box_X->Margin = System::Windows::Forms::Padding(2);
			this->eAssortingNutWasher_Box_X->Name = L"eAssortingNutWasher_Box_X";
			this->eAssortingNutWasher_Box_X->Size = System::Drawing::Size(58, 23);
			this->eAssortingNutWasher_Box_X->TabIndex = 11;
			this->eAssortingNutWasher_Box_X->Text = L"-16";
			this->eAssortingNutWasher_Box_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ePole_Box_XY
			// 
			this->ePole_Box_XY->AutoSize = true;
			this->ePole_Box_XY->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->ePole_Box_XY->Location = System::Drawing::Point(30, 25);
			this->ePole_Box_XY->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ePole_Box_XY->Name = L"ePole_Box_XY";
			this->ePole_Box_XY->Size = System::Drawing::Size(90, 13);
			this->ePole_Box_XY->TabIndex = 5;
			this->ePole_Box_XY->Text = L"圓柱盒座標:";
			// 
			// eAssortingBolt_Box_Y
			// 
			this->eAssortingBolt_Box_Y->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eAssortingBolt_Box_Y->Location = System::Drawing::Point(194, 124);
			this->eAssortingBolt_Box_Y->Margin = System::Windows::Forms::Padding(2);
			this->eAssortingBolt_Box_Y->Name = L"eAssortingBolt_Box_Y";
			this->eAssortingBolt_Box_Y->Size = System::Drawing::Size(58, 23);
			this->eAssortingBolt_Box_Y->TabIndex = 10;
			this->eAssortingBolt_Box_Y->Text = L"68.3";
			this->eAssortingBolt_Box_Y->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// eAssortingBolt_Box_XY
			// 
			this->eAssortingBolt_Box_XY->AutoSize = true;
			this->eAssortingBolt_Box_XY->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eAssortingBolt_Box_XY->Location = System::Drawing::Point(4, 127);
			this->eAssortingBolt_Box_XY->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->eAssortingBolt_Box_XY->Name = L"eAssortingBolt_Box_XY";
			this->eAssortingBolt_Box_XY->Size = System::Drawing::Size(120, 13);
			this->eAssortingBolt_Box_XY->TabIndex = 1;
			this->eAssortingBolt_Box_XY->Text = L"分類螺栓盒座標:";
			// 
			// eAssortingBolt_Box_X
			// 
			this->eAssortingBolt_Box_X->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eAssortingBolt_Box_X->Location = System::Drawing::Point(124, 124);
			this->eAssortingBolt_Box_X->Margin = System::Windows::Forms::Padding(2);
			this->eAssortingBolt_Box_X->Name = L"eAssortingBolt_Box_X";
			this->eAssortingBolt_Box_X->Size = System::Drawing::Size(58, 23);
			this->eAssortingBolt_Box_X->TabIndex = 9;
			this->eAssortingBolt_Box_X->Text = L"-16";
			this->eAssortingBolt_Box_X->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// eBolt_Box_XY
			// 
			this->eBolt_Box_XY->AutoSize = true;
			this->eBolt_Box_XY->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eBolt_Box_XY->Location = System::Drawing::Point(17, 61);
			this->eBolt_Box_XY->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->eBolt_Box_XY->Name = L"eBolt_Box_XY";
			this->eBolt_Box_XY->Size = System::Drawing::Size(105, 13);
			this->eBolt_Box_XY->TabIndex = 4;
			this->eBolt_Box_XY->Text = L"鎖螺栓盒座標:";
			// 
			// eAssortingNutWasher_Box_XY
			// 
			this->eAssortingNutWasher_Box_XY->AutoSize = true;
			this->eAssortingNutWasher_Box_XY->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eAssortingNutWasher_Box_XY->Location = System::Drawing::Point(4, 163);
			this->eAssortingNutWasher_Box_XY->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->eAssortingNutWasher_Box_XY->Name = L"eAssortingNutWasher_Box_XY";
			this->eAssortingNutWasher_Box_XY->Size = System::Drawing::Size(120, 13);
			this->eAssortingNutWasher_Box_XY->TabIndex = 3;
			this->eAssortingNutWasher_Box_XY->Text = L"分類螺帽盒座標:";
			// 
			// eHole_Box_XY
			// 
			this->eHole_Box_XY->AutoSize = true;
			this->eHole_Box_XY->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->eHole_Box_XY->Location = System::Drawing::Point(30, 96);
			this->eHole_Box_XY->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->eHole_Box_XY->Name = L"eHole_Box_XY";
			this->eHole_Box_XY->Size = System::Drawing::Size(90, 13);
			this->eHole_Box_XY->TabIndex = 2;
			this->eHole_Box_XY->Text = L"洞洞盒座標:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->txtb_CameraHeight);
			this->groupBox1->Controls->Add(this->Btn_CameraConfirm);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(834, 341);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(222, 215);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Camera / Img Calibrate";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(144, 121);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(53, 23);
			this->textBox5->TabIndex = 14;
			this->textBox5->Text = L"71.11";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(43, 121);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(53, 23);
			this->textBox4->TabIndex = 13;
			this->textBox4->Text = L"30.31";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(114, 124);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(24, 15);
			this->label7->TabIndex = 12;
			this->label7->Text = L"LY:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(9, 124);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 15);
			this->label6->TabIndex = 11;
			this->label6->Text = L"LX:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(112, 93);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(26, 15);
			this->label4->TabIndex = 10;
			this->label4->Text = L"RY:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(9, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 15);
			this->label3->TabIndex = 9;
			this->label3->Text = L"RX:";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(144, 88);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(53, 23);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"49.34";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(43, 89);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(53, 23);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"29.7";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &FormIA::textBox2_TextChanged);
			// 
			// txtb_CameraHeight
			// 
			this->txtb_CameraHeight->Font = (gcnew System::Drawing::Font(L"Cambria", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->txtb_CameraHeight->Location = System::Drawing::Point(100, 37);
			this->txtb_CameraHeight->Name = L"txtb_CameraHeight";
			this->txtb_CameraHeight->Size = System::Drawing::Size(100, 23);
			this->txtb_CameraHeight->TabIndex = 6;
			this->txtb_CameraHeight->Text = L"36";
			this->txtb_CameraHeight->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Btn_CameraConfirm
			// 
			this->Btn_CameraConfirm->BackColor = System::Drawing::Color::Cornsilk;
			this->Btn_CameraConfirm->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Btn_CameraConfirm->Location = System::Drawing::Point(67, 169);
			this->Btn_CameraConfirm->Name = L"Btn_CameraConfirm";
			this->Btn_CameraConfirm->Size = System::Drawing::Size(89, 30);
			this->Btn_CameraConfirm->TabIndex = 5;
			this->Btn_CameraConfirm->Text = L"確認";
			this->Btn_CameraConfirm->UseVisualStyleBackColor = false;
			this->Btn_CameraConfirm->Click += gcnew System::EventHandler(this, &FormIA::Btn_CameraConfirm_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"影像中心";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"DFKai-SB", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(6, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"攝影機高度:";
			// 
			// timerImgTest
			// 
			this->timerImgTest->Tick += gcnew System::EventHandler(this, &FormIA::timerImgTest_Tick);
			// 
			// FormIA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaShell;
			this->ClientSize = System::Drawing::Size(1366, 576);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Coordinate);
			this->Controls->Add(this->ReviseParameter);
			this->Controls->Add(this->ArmStatus);
			this->Controls->Add(this->Rmove);
			this->Controls->Add(this->gripper);
			this->Controls->Add(this->excute);
			this->Controls->Add(this->Amove);
			this->Controls->Add(this->speed);
			this->Controls->Add(this->Position);
			this->Controls->Add(this->Btn_CameraGoal_L);
			this->Controls->Add(this->Btn_CameraGoal_R);
			this->Controls->Add(this->Btn_IA_OpenVision);
			this->Name = L"FormIA";
			this->Load += gcnew System::EventHandler(this, &FormIA::FormIA_Load);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormIA::FormIA_FormClosing);
			this->Position->ResumeLayout(false);
			this->Position->PerformLayout();
			this->speed->ResumeLayout(false);
			this->speed->PerformLayout();
			this->Amove->ResumeLayout(false);
			this->Amove->PerformLayout();
			this->excute->ResumeLayout(false);
			this->gripper->ResumeLayout(false);
			this->Rmove->ResumeLayout(false);
			this->Rmove->PerformLayout();
			this->ArmStatus->ResumeLayout(false);
			this->ArmStatus->PerformLayout();
			this->ReviseParameter->ResumeLayout(false);
			this->ReviseParameter->PerformLayout();
			this->Coordinate->ResumeLayout(false);
			this->Coordinate->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


//=========================================//
CObject* Objects;
CBox* Boxes;
Graphics^ g;
static Pen^ pen;
SolidBrush^ brush;
Bitmap^ bmp;
Graphics^ Draw;
System::Drawing::Font^ font;
int FinalTaskID;
DataGridViewRow^ NewRow;
//////////////////////////////////////////////////////////////
double start_point_x, start_point_y;
double end_point_x, end_point_y;
double tmp_point_x, tmp_point_y;
double add_x, add_y;
int order;
//eSelectArmState state;
//bool Flag_Bk_Enable;
///////////////////////////////////////////////////////////////
CGripper	*Gripper;
CArm	    *Arm;
CIA_ArmInfo *CIAArmInfo;

bool Flag_Bk_Enable;

bool fnMVP_ShowWindow_Flag;

//=========================================//
static int IntelAssort_ImgObjTotalNum;	
static ScrewParam* IntelAssort_ImageObjectInfo = NULL;
static bool IntelAssort_ImageFlag = false;
//=========================================//

public: static void IA_ImageObjInfo(int ObjNum,ScrewParam* pObjList)
		{
			IntelAssort_ImgObjTotalNum	= ObjNum;
			IntelAssort_ImageObjectInfo = pObjList;
			IntelAssort_ImageFlag		= true;
			//cout << "objnum" << ObjNum << endl ;

// 			system("cls");
// 			for(int i = 0;i<ObjNum;i++)
// 			{
// 				if(pObjList[i].nClassId == 0)
// 				{
// 					cout<<pObjList[i].nClassId;
// 					cout<<" [ "<<pObjList[i].nWidth<<","<<pObjList[i].nHeight<<" ] "<<endl;
// 					cout<<(pObjList[i].nx + (pObjList[i].nWidth / 2))
// 						<<" , "<<(pObjList[i].ny + (pObjList[i].nHeight / 2))<<endl;
// 					cout<<"Rotation: "<<pObjList[i].fAngle<<endl;
// 					
// 				}
// 			}
// 
// 			system("cls");
// 			for(int i = 0;i<ObjNum;i++)
// 			{
// 				if(pObjList[i].nClassId == 1)
// 				{
// 					cout<<pObjList[i].nClassId;
// 					cout<<" [ "<<pObjList[i].nWidth<<","<<pObjList[i].nHeight<<" ] "<<endl;
// 					cout<<pObjList[i].nHeight<<" , "
// 						<<pObjList[i].nWidth<<endl;
// 				}
// 			}
		}
private: System::Void Btn_IA_OpenVision_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 fnMVP_ShowWindow_Flag = !fnMVP_ShowWindow_Flag;
			 fnMVP_ShowWindow(fnMVP_ShowWindow_Flag);
			 if(fnMVP_ShowWindow_Flag)	this->Btn_IA_OpenVision->Text = "Close Vision";
			 else this->Btn_IA_OpenVision->Text = "Open Vision";
		 }
private: System::Void Btn_CameraGoal_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Button^ btnPtr = (Button^) sender;
			 int CtrlTar = Convert::ToInt32(btnPtr->Tag);

			 CIAArmInfo->ArmMoveTo_CameraCoordinate(CtrlTar);
		 }
private: bool EnterPositionValue( string AxisName, TextBox^ txtAxis, double &Number )
				 {
					 Double Num;

					 if( Double::TryParse( txtAxis->Text, Num ) )
					 {
						 Number = Convert::ToDouble( txtAxis->Text );
						 return true;
					 }
					 else
					 {
						 ::MessageBox( NULL, TEXT( (AxisName + " is NOT valid").c_str() ), 
							 TEXT( "Command Error" ), MB_OK | MB_ICONERROR );
						 return false;
					 }
				 }

private: bool EnterEulerAngleValue( string EulerName, TextBox^ txtEuler, double &Number )
						  {
							  Double Num;
							  double tmpValue;
							  if( Double::TryParse( txtEuler->Text, Num ) )
							  {
								  tmpValue = Convert::ToDouble( txtEuler->Text );
								  tmpValue*= M_PI / 180.0;
								  if( tmpValue > M_PI || tmpValue < -M_PI )
								  {
									  ::MessageBox( NULL, TEXT( (EulerName + " is over RANGE").c_str() ), 
										  TEXT( "Command Error" ), MB_OK | MB_ICONERROR );
									  return false;
								  }
								  Number = tmpValue;
								  return true;
							  }
							  else
							  {
								  ::MessageBox( NULL, TEXT( (EulerName + " is NOT valid").c_str() ), 
									  TEXT( "Command Error" ), MB_OK | MB_ICONERROR );
								  return false;
							  }
						  }

// public: System::Void IA_Set_Deviceconnect( CArm* ArmPtr, CGripper* GripperPtr,CArmDevice* ArmDevicePtr)
// 		 {
// 			CIAArmInfo->IA_Set_Device(ArmPtr,GripperPtr,ArmDevicePtr);
// 		 }
// static int b = 0;
// int NumberX[18] = {0};
// void TurnX(double Number)
//  		{
// 
//  			NumberX[b] = Number;
// 			b++;
// 			if(b==18)
// 			{
// 				b=0;
// 			}
//   		}


private: System::Void FormIA_Load(System::Object^  sender, System::EventArgs^  e)
		 {
			 //printf("Form Load\n");
			 CIAArmInfo = new CIA_ArmInfo();
			 timerRefresh->Enabled = true;
// 			 g = this->pictureBox1->CreateGraphics();
// 			 pen = gcnew Pen(Color::Black, 2);					
// 			 brush = gcnew SolidBrush(Color::Red);				
// 			 font = gcnew System::Drawing::Font("Calibri", 12);
// 			 bmp = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);		
// 			 Draw = Graphics::FromImage(bmp);				
// 			 Draw->Clear(Color::White);				
// 			 this->pictureBox1->BackgroundImage = bmp;
		 }
private: System::Void speed_Enter(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
private: System::Void Ppitch_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void APitchtxt_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
//==============================================Absolutely Move=======================================================//
private: System::Void APtoP_Click(System::Object^  sender, System::EventArgs^  e)					//PtoP//
		 {					

			 CVector3D	  Goal;
			 tsEulerAngle Eular;

			 if(EnterPositionValue("X-Axis", AXtxt, Goal.x) == false)
				 return;
			 if(EnterPositionValue("Y-Axis", AYtxt, Goal.y) == false)
				 return;
			 if(EnterPositionValue("Z-Axis", AZtxt, Goal.z) == false)
				 return;

			 if(EnterEulerAngleValue("Pitch", APitchtxt, Eular.Pitch) == false)
				 return;
			 if(EnterEulerAngleValue("Roll", ARolltxt, Eular.Roll) == false)
				 return;
			 if(EnterEulerAngleValue("Yaw", AYawtxt, Eular.Yaw) == false)
				 return;

			 Arm->PtoP->Command(CArmControl::eMOVE_ABS, Goal, Eular);

		 }

private: System::Void Aline_Click(System::Object^  sender, System::EventArgs^  e)					//Line// 
		 {					

			 CVector3D	  Goal;
			 tsEulerAngle Eular;

			 if(EnterPositionValue("X-Axis", AXtxt, Goal.x) == false)
				 return;
			 if(EnterPositionValue("Y-Axis", AYtxt, Goal.y) == false)
				 return;
			 if(EnterPositionValue("Z-Axis", AZtxt, Goal.z) == false)
				 return;

			 if(EnterEulerAngleValue("Pitch", APitchtxt, Eular.Pitch) == false)
				 return;
			 if(EnterEulerAngleValue("Roll", ARolltxt, Eular.Roll) == false)
				 return;
			 if(EnterEulerAngleValue("Yaw", AYawtxt, Eular.Yaw) == false)
				 return;

			 Arm->Line->Command(CArmControl::eMOVE_ABS, Goal, Eular);

		 }
//=============================================Relative Move========================================================//
		 
private: System::Void RminusZ_Click(System::Object^  sender, System::EventArgs^  e)					//-Z// 
		 {					//-Z//

			 Button^ btnPtr = (Button^) sender;
			 int CtrlTar = Convert::ToInt32(btnPtr->Tag);

			 CVector3D	  Goal(0,0,0);
			 tsEulerAngle Eular = {0,0,0,0,0};

			 switch(abs(CtrlTar))
			 {
			 case 1:
				 if(EnterPositionValue("Rel X", Rvaluetxt, Goal.x) == false)
					 return;
				 Goal.x = (CtrlTar > 0) ? Goal.x : -1 * Goal.x;
				 break;
			 case 2:
				 if(EnterPositionValue("Rel Y", Rvaluetxt, Goal.y) == false)
					 return;
				 Goal.y = (CtrlTar > 0) ? Goal.y : -1 * Goal.y;
				 break;
			 case 3:
				 if(EnterPositionValue("Rel Z", Rvaluetxt, Goal.z) == false)
					 return;
				 Goal.z = (CtrlTar > 0) ? Goal.z : -1 * Goal.z;
				 break;
			 }
			 Arm->PtoP->Command(CPtoP::eMOVE_REL, Goal, Eular);

		 }

private: System::Void RplusZ_Click(System::Object^  sender, System::EventArgs^  e)					//+Z// 
		 {					

			 Button^ btnPtr = (Button^) sender;
			 int CtrlTar = Convert::ToInt32(btnPtr->Tag);

			 CVector3D	  Goal(0,0,0);
			 tsEulerAngle Eular = {0,0,0,0,0};

			 switch(abs(CtrlTar))
			 {
			 case 1:
				 if(EnterPositionValue("Rel X", Rvaluetxt, Goal.x) == false)
					 return;
				 Goal.x = (CtrlTar > 0) ? Goal.x : -1 * Goal.x;
				 break;
			 case 2:
				 if(EnterPositionValue("Rel Y", Rvaluetxt, Goal.y) == false)
					 return;
				 Goal.y = (CtrlTar > 0) ? Goal.y : -1 * Goal.y;
				 break;
			 case 3:
				 if(EnterPositionValue("Rel Z", Rvaluetxt, Goal.z) == false)
					 return;
				 Goal.z = (CtrlTar > 0) ? Goal.z : -1 * Goal.z;
				 break;

			 }
			 Arm->PtoP->Command(CPtoP::eMOVE_REL, Goal, Eular);

		 }

private: System::Void RplusY_Click(System::Object^  sender, System::EventArgs^  e)					//+Y// 
		 {					

			 Button^ btnPtr = (Button^) sender;
			 int CtrlTar = Convert::ToInt32(btnPtr->Tag);

			 CVector3D	  Goal(0,0,0);
			 tsEulerAngle Eular = {0,0,0,0,0};

			 switch(abs(CtrlTar))
			 {
			 case 1:
				 if(EnterPositionValue("Rel X", Rvaluetxt, Goal.x) == false)
					 return;
				 Goal.x = (CtrlTar > 0) ? Goal.x : -1 * Goal.x;
				 break;
			 case 2:
				 if(EnterPositionValue("Rel Y", Rvaluetxt, Goal.y) == false)
					 return;
				 Goal.y = (CtrlTar > 0) ? Goal.y : -1 * Goal.y;
				 break;
			 case 3:
				 if(EnterPositionValue("Rel Z", Rvaluetxt, Goal.z) == false)
					 return;
				 Goal.z = (CtrlTar > 0) ? Goal.z : -1 * Goal.z;
				 break;
		
			 }
			 Arm->PtoP->Command(CPtoP::eMOVE_REL, Goal, Eular);

		 }

private: System::Void RminusY_Click(System::Object^  sender, System::EventArgs^  e)					//-Y// 
		 {					
			 Button^ btnPtr = (Button^) sender;
			 int CtrlTar = Convert::ToInt32(btnPtr->Tag);

			 CVector3D	  Goal(0,0,0);
			 tsEulerAngle Eular = {0,0,0,0,0};

			 switch(abs(CtrlTar))
			 {
			 case 1:
				 if(EnterPositionValue("Rel X", Rvaluetxt, Goal.x) == false)
					 return;
				 Goal.x = (CtrlTar > 0) ? Goal.x : -1 * Goal.x;
				 break;
			 case 2:
				 if(EnterPositionValue("Rel Y", Rvaluetxt, Goal.y) == false)
					 return;
				 Goal.y = (CtrlTar > 0) ? Goal.y : -1 * Goal.y;
				 break;
			 case 3:
				 if(EnterPositionValue("Rel Z", Rvaluetxt, Goal.z) == false)
					 return;
				 Goal.z = (CtrlTar > 0) ? Goal.z : -1 * Goal.z;
				 break;
			 
			 }
			 Arm->PtoP->Command(CPtoP::eMOVE_REL, Goal, Eular);

		 }

private: System::Void RminusX_Click(System::Object^  sender, System::EventArgs^  e)					//-X// 
		 {					

			 Button^ btnPtr = (Button^) sender;
			 int CtrlTar = Convert::ToInt32(btnPtr->Tag);

			 CVector3D	  Goal(0,0,0);
			 tsEulerAngle Eular = {0,0,0,0,0};

			 switch(abs(CtrlTar))
			 {
			 case 1:
				 if(EnterPositionValue("Rel X", Rvaluetxt, Goal.x) == false)
					 return;
				 Goal.x = (CtrlTar > 0) ? Goal.x : -1 * Goal.x;
				 break;
			 case 2:
				 if(EnterPositionValue("Rel Y", Rvaluetxt, Goal.y) == false)
					 return;
				 Goal.y = (CtrlTar > 0) ? Goal.y : -1 * Goal.y;
				 break;
			 case 3:
				 if(EnterPositionValue("Rel Z", Rvaluetxt, Goal.z) == false)
					 return;
				 Goal.z = (CtrlTar > 0) ? Goal.z : -1 * Goal.z;
				 break;
			 
			 }
			 Arm->PtoP->Command(CPtoP::eMOVE_REL, Goal, Eular);

		 }
private: System::Void RplusX_Click(System::Object^  sender, System::EventArgs^  e)					//+X// 
		 {					

			 Button^ btnPtr = (Button^) sender;
			 int CtrlTar = Convert::ToInt32(btnPtr->Tag);

			 CVector3D	  Goal(0,0,0);
			 tsEulerAngle Eular = {0,0,0,0,0};

			 switch(abs(CtrlTar))
			 {
			 case 1:
				 if(EnterPositionValue("Rel X", Rvaluetxt, Goal.x) == false)
					 return;
				 Goal.x = (CtrlTar > 0) ? Goal.x : -1 * Goal.x;
				 break;
			 case 2:
				 if(EnterPositionValue("Rel Y", Rvaluetxt, Goal.y) == false)
					 return;
				 Goal.y = (CtrlTar > 0) ? Goal.y : -1 * Goal.y;
				 break;
			 case 3:
				 if(EnterPositionValue("Rel Z", Rvaluetxt, Goal.z) == false)
					 return;
				 Goal.z = (CtrlTar > 0) ? Goal.z : -1 * Goal.z;
				 break;
			 
			 }
			 Arm->PtoP->Command(CPtoP::eMOVE_REL, Goal, Eular);

		 }


//============================================Gripper=========================================================//
private: System::Void allopen_Click(System::Object^  sender, System::EventArgs^  e)					//全開// 
		 {					
	
			 Gripper->Set_GripperCommand(CGripper::eCMD_BACKHOME);

		 }

private: System::Void open1_Click(System::Object^  sender, System::EventArgs^  e)					//寬度1// 
		 {					

			Gripper->Set_GripperCommand(CGripper::eCMD_CATCHTO1);

		 }
private: System::Void open2_Click(System::Object^  sender, System::EventArgs^  e)					//寬度2// 
		 {					

			Gripper->Set_GripperCommand(CGripper::eCMD_CATCHTO2);

		}


private: System::Void littleopen_Click(System::Object^  sender, System::EventArgs^  e)				//鬆開// 
		 {			    

			Gripper->Set_GripperCommand(CGripper::eCMD_LOOSEN);

		 }


private: System::Void close_Click(System::Object^  sender, System::EventArgs^  e)					//夾緊// 
		 {					   

			Gripper->Set_GripperCommand(CGripper::eCMD_CATCH);

		 }



//============================================Speed========================================================//

private: System::Void confirm_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

			 double speedarm;
			 speedarm= Convert::ToDouble( speedtxt->Text);
			 Arm->Set_SpeedPercent(speedarm);
			 CIAArmInfo->SpeedValue = Convert::ToDouble(speedtxt->Text);

		 }
//=============================================TimerRefresh========================================================//

private: System::Void timerRefresh_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {

			 const CVector3D& End_Pos	   = Arm->Get_EndPos();
			 const tsEulerAngle& End_Euler = Arm->Get_EndEuler();

			 labX->Text = String::Format("{0:F2} ",End_Pos.x );
			 labY->Text = String::Format("{0:F2} ",End_Pos.y );
			 labZ->Text = String::Format("{0:F2} ",End_Pos.z );

			 labRoll->Text  = String::Format("{0:F2} ",End_Euler.Roll * 180.0 /M_PI );  
			 labPitch->Text = String::Format("{0:F2} ",End_Euler.Pitch* 180.0 /M_PI ); 
			 labYaw->Text   = String::Format("{0:F2} ",End_Euler.Yaw  * 180.0 /M_PI );

		 }

//================================================Refresh=====================================================//

private: System::Void refresh_Click(System::Object^  sender, System::EventArgs^  e) 
		 {

			 const CVector3D& End_Pos	   = Arm->Get_EndPos();
			 const tsEulerAngle& End_Euler = Arm->Get_EndEuler();

			 AXtxt->Text = String::Format("{0:F2} ",End_Pos.x );
			 AYtxt->Text = String::Format("{0:F2} ",End_Pos.y );
			 AZtxt->Text = String::Format("{0:F2} ",End_Pos.z );

			 APitchtxt->Text = String::Format("{0:F2} ",End_Euler.Pitch* 180.0 /M_PI ); 
			 ARolltxt->Text  = String::Format("{0:F2} ",End_Euler.Roll * 180.0 /M_PI );  
			 AYawtxt->Text   = String::Format("{0:F2} ",End_Euler.Yaw  * 180.0 /M_PI );

		 }
public: System::Void Set_Device(CArm* ArmPtr, CGripper* GripperPtr)
		{
			CIAArmInfo->IA_Set_Device(ArmPtr,GripperPtr);
			Arm = ArmPtr;
			Gripper = GripperPtr;
			
		}

//================================================策略=====================================================//




private: System::Void mission1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {	
			 CVector3D	  Goal(-16,68.3,15);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void FormIA_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		 {
			 e->Cancel=true;
			 this->Hide();
		 }
private: System::Void Estart_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //CIAArmInfo->GripperCatch(CGripper::eCMD_BACKHOME);
			 //IntelAssort_BoxInformationConnect(pBox);
			 
			  CIAArmInfo->IA_Initialize();
			  timerImgTest->Enabled = false;
			  timerstart->Enabled = true; 
					 
		 }
private: System::Void timerstart_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 //cout << "IntelAssort_ImageFlag:" << IntelAssort_ImageFlag << endl;
			 CIAArmInfo->Set_ImgVarInfo(IntelAssort_ImageFlag,IntelAssort_ImgObjTotalNum,IntelAssort_ImageObjectInfo);
			 CIAArmInfo->ImgTest_Flag = false;
			 CIAArmInfo->Task_Flow();
			 //CIAArmInfo->Mission_Excute();
			 switch(CIAArmInfo->Mission_Type)
			 {
			 case 0:
				 StatusMission->Text = "Get_Image";
				 break;
			 case 1:
				 StatusMission->Text = "Put_In_Washer1";
				 break;
			 case 2:
				 StatusMission->Text = "Insert_Bolt";
				 break;
			 case 3:
				 StatusMission->Text = "Put_In_Nut";
				 break;
			 case 4:
				 StatusMission->Text = "Put_In_Washer2";
				 break;
			 case 5:
				 StatusMission->Text = "Fasten_Nut";
				 break;
			 case 6:
				 StatusMission->Text = "Classify_Nut";
				 break;
			 case 7:
				 StatusMission->Text = "Classify_Washer";
				 break;
			 case 8:
				 StatusMission->Text = "Classify_Bolt";
				 break;
			 case 9:
				 StatusMission->Text = "LeavedObject";
				 break;
			 case 10:
				 StatusMission->Text = "Mission_End";
				 break;
			 default:
				 break;
			 }
			 StatusTimes->Text = Convert::ToString(CIAArmInfo->cnt);
			 StatusMotion->Text = Convert::ToString(CIAArmInfo->motion);
			 ObPositionX->Text = Convert::ToString(CIAArmInfo->XValue);
			 ObPositionY->Text = Convert::ToString(CIAArmInfo->YValue);
			 ObPositionZ->Text = Convert::ToString(CIAArmInfo->ZValue);
			 //StatusMission->Text = Convert::ToString(CIAArmInfo->Mission_Type);
			/* CIAArmInfo->Get_Info();*/
			 
		 }
private: System::Void ImgTest_Btn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CIAArmInfo->IA_Initialize();
			 timerstart->Enabled = false;
			 timerImgTest->Enabled =true;
		 }
private: System::Void timerImgTest_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CIAArmInfo->Set_ImgVarInfo(IntelAssort_ImageFlag,IntelAssort_ImgObjTotalNum,IntelAssort_ImageObjectInfo);
			 CIAArmInfo->ImgTest_Flag = true;
			 CIAArmInfo->Task_Flow();
			 StatusMission->Text = "ImgTest Mode";
		 }
private: System::Void Estop_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CIAArmInfo->ArmStop();
			 CIAArmInfo->ImgTest_Flag = false;
			 timerstart->Enabled = false;
			 timerImgTest->Enabled= false;
			 CIAArmInfo->IA_Initialize();
		 }
private: System::Void StatusComfirm_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CIAArmInfo->Height_of_Classify = Convert::ToDouble(ClassfyHeightTXT->Text);//////////更改分類盒高度
			 CIAArmInfo->Height_of_Hole_Box = Convert::ToDouble(HeightOfHoleBoxTXT->Text);////////更改洞洞盒高度
			 CIAArmInfo->Height_of_Pole_Box = Convert::ToDouble(PutInNutHeightTXT->Text);/////////更改圓柱盒高度
			 CIAArmInfo->Height_of_Fasten = Convert::ToDouble(FastenHeightTXT->Text);/////////////更改鎖螺帽盒高度
			 CIAArmInfo->Height_of_Catch = Convert::ToDouble(CatchHeightTXT->Text);///////////////更改夾取高度
		 }

private: System::Void mission2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CVector3D	  Goal(-30,76.5,15);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void mission3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CVector3D	  Goal(-16,55.3,15);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void mission4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CVector3D	  Goal(-30,62.5,15);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void mission5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CVector3D	  Goal(21,37,2);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void mission6_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CVector3D	  Goal(-30,48.5,15);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void mission7_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 CVector3D	  Goal(31,72,2);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
//===============================================ImageSimulation==============================================//
private: System::Void Btn_ImgRefresh_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
// 			 Draw->Clear(Color::White);
// 			 g->Clear(Color::White);
// 			 srand(time(0));
// 			 dataGridView1->Rows->Clear();
// 			 //timer1->Stop();
// 			 //timer2->Stop();
// 			 //Flag_Bk_Enable = false;
// 			 //Arm_State->Text = "Idle";
// 			 //============================================//
// 			 Draw_Site();                                //畫場地線
// 			 //============================================//
// 			 Boxes = new CBox[5];	                     //宣告盒子
// 			 ///////////////////////////////////////////
// 			 Objects = new CObject[18];                  //宣告物件
// 			 ///////////////////////////////////////////
// 			 Generate_Object();                          //產生物件			 
// 			 ///////////////////////////////////////////
// 			 Random_Set_Object_Position();               //隨機指定物件位置				 
// 			 ///////////////////////////////////////////////////////////////////////////////
// 			 for(int i = 0; i < 18; i++)                 //畫物件
// 			 {
// 				 Draw_Object(&Objects[i]);
// 			 }
// 			 ////////////////////////////////////////////////
// 			 g->DrawImage(bmp, 0, 0);
// 			 ////////////////////////////////////////////////
// 			 //Sequence_Object();  //物件排序
// 			 ///////////////////////////////////////////////////////////////////////////////
// 			 for(int i = 0; i < 18; i++)                //將物件資料輸入至表單
// 			 {
// 				 Input_Data_to_DataGridView(&Objects[i]);
// 			 }
// 			 CIAArmInfo->Get_Objects(Objects);
// 			 label1->Text = Convert::ToString(Objects[17].Get_Tf_x());
// 			 label2->Text = Convert::ToString(Objects[17].Get_Tf_y());
// 			 label3->Text = Convert::ToString(Objects[17].Get_ObjType());
		 }
//=================================================================================================//
private: void Draw_Site(void)  //畫場地線副函式
		 {
// 			 pen->Color = Color::Black;
// 			 Draw->DrawLine(pen, 140, 0, 140, 296);
// 			 Draw->DrawRectangle(pen, 332, 76, 40, 40);
// 			 Draw->DrawRectangle(pen, 332, 130, 40, 40);
// 			 Draw->DrawRectangle(pen, 332, 184, 40, 40);
// 			 Draw->DrawRectangle(pen, 268, 96, 40, 40);
// 			 Draw->DrawRectangle(pen, 268, 160, 40, 40);
		 }
//////////////////////////////////////////////////////////////////////////////////////////////////////
private: void Draw_Object(CObject* objs_data)  //畫物件副函式
		 {
// 			 double vertex1[2], vertex2[2], vertex3[2], vertex4[2], vertex5[2], vertex6[2], vertex7[2], vertex8[2];
// 			 double final_vertex1[2], final_vertex2[2], final_vertex3[2], final_vertex4[2], final_vertex5[2], final_vertex6[2], final_vertex7[2], final_vertex8[2];	 
// 			 pen->Color = Color::Gray;
// 
// 			 switch(objs_data->Get_ObjType())
// 			 {
// 			 case eBolt:						 
// 				 brush -> Color = Color::Black;
// 				 vertex1[0] = (objs_data->Get_x()) - 4.2;
// 				 vertex1[1] = (objs_data->Get_y()) +  1.6;
// 				 vertex2[0] = (objs_data->Get_x()) + 4.2;
// 				 vertex2[1] = (objs_data->Get_y()) +  1.6;
// 				 vertex3[0] = (objs_data->Get_x()) - 4.2;
// 				 vertex3[1] = (objs_data->Get_y()) -  1.6;
// 				 vertex4[0] = (objs_data->Get_x()) + 4.2;
// 				 vertex4[1] = (objs_data->Get_y()) -  1.6;
// 				 vertex5[0] = (objs_data->Get_x()) -2.3;
// 				 vertex5[1] = (objs_data->Get_y()) -  1.6;
// 				 vertex6[0] = (objs_data->Get_x()) +2.3;
// 				 vertex6[1] = (objs_data->Get_y()) -  1.6;
// 				 vertex7[0] = (objs_data->Get_x()) -2.3;
// 				 vertex7[1] = (objs_data->Get_y()) -  21.2;
// 				 vertex8[0] = (objs_data->Get_x()) +2.3;
// 				 vertex8[1] = (objs_data->Get_y()) -  21.2;
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex1, final_vertex1, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex2, final_vertex2, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex3, final_vertex3, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex4, final_vertex4, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex5, final_vertex5, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex6, final_vertex6, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex7, final_vertex7, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex8, final_vertex8, objs_data->Get_Rotation());
// 				 Draw -> FillPolygon(brush, Point_of_vertex(final_vertex1, final_vertex2, final_vertex3));
// 				 Draw -> FillPolygon(brush, Point_of_vertex(final_vertex2, final_vertex3, final_vertex4));
// 				 Draw -> FillPolygon(brush, Point_of_vertex(final_vertex5, final_vertex6, final_vertex7));
// 				 Draw -> FillPolygon(brush, Point_of_vertex(final_vertex6, final_vertex7, final_vertex8));
// 				 break;
// 
// 			 case eWasher:						
// 				 brush -> Color = Color::Black;	
// 				 Draw -> DrawEllipse(pen, (objs_data -> Get_x()-4.8), (objs_data->Get_y()-4.8),(float)9.6,(float)9.6);
// 				 brush -> Color = Color::White;
// 				 Draw -> DrawEllipse(pen, (objs_data -> Get_x()-2.4), (objs_data->Get_y()-2.4),(float)5.2,(float)5.2);
// 				 break;
// 
// 			 case eNut:						
// 				 brush -> Color = Color::Black;	
// 				 vertex1[0] = (objs_data->Get_x());
// 				 vertex1[1] = (objs_data->Get_y()) + (1.05)*4.0;
// 				 vertex2[0] = (objs_data->Get_x()) - (0.925)*4.0;
// 				 vertex2[1] = (objs_data->Get_y()) + (0.55)*4.0;
// 				 vertex3[0] = (objs_data->Get_x()) + (0.925)*4.0;
// 				 vertex3[1] = (objs_data->Get_y()) + (0.55)*4.0;
// 				 vertex4[0] = (objs_data->Get_x()) - (0.925)*4.0;
// 				 vertex4[1] = (objs_data->Get_y()) - (0.55)*4.0;
// 				 vertex5[0] = (objs_data->Get_x()) + (0.925)*4.0;
// 				 vertex5[1] = (objs_data->Get_y()) - (0.55)*4.0;
// 				 vertex6[0] = (objs_data->Get_x());
// 				 vertex6[1] = (objs_data->Get_y()) - (1.05)*4.0;
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex1, final_vertex1, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex2, final_vertex2, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex3, final_vertex3, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex4, final_vertex4, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex5, final_vertex5, objs_data->Get_Rotation());
// 				 Rotation_Matrix(objs_data->Get_x(), objs_data->Get_y(), vertex6, final_vertex6, objs_data->Get_Rotation());
// 				 Draw->FillPolygon(brush, Point_of_vertex(final_vertex1, final_vertex2, final_vertex3));
// 				 Draw->FillPolygon(brush, Point_of_vertex(final_vertex2, final_vertex3, final_vertex4));
// 				 Draw->FillPolygon(brush, Point_of_vertex(final_vertex3, final_vertex4, final_vertex5));
// 				 Draw->FillPolygon(brush, Point_of_vertex(final_vertex4, final_vertex5, final_vertex6));
// 				 break;
//			 }
		 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: void Rotation_Matrix(double x, double y, double* vertex, double* final_vertex, double rotation)  //旋轉矩陣副函式
		 {
			 final_vertex[0] = cos(degree_to_pi(rotation))*(vertex[0]-x) - sin(degree_to_pi(rotation))*(vertex[1]-y) + x;
			 final_vertex[1] = sin(degree_to_pi(rotation))*(vertex[0]-x) + cos(degree_to_pi(rotation))*(vertex[1]-y) + y;
		 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: array <PointF>^ Point_of_vertex(double* vertex_1, double* vertex_2, double* vertex_3)  //宣告一個PointF陣列副函式
		 {
			 array <PointF>^ p_Array = { PointF(vertex_1[0], vertex_1[1]),
				                         PointF(vertex_2[0], vertex_2[1]),
				                         PointF(vertex_3[0], vertex_3[1])};
			 return p_Array;
		 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: double degree_to_pi(double degree)  //角度單位轉換(度度換徑度)副函式
		 {
			 return degree*3.14159265359/180.0;
		 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: void Generate_Object(void)  //產生物件副函式
		 {
// 			 int obj_order = 0;
// 			 for(int i = 0; i < 18; i++)
// 			 {
// 				 if((0 <= i) && (i <= 6))
// 				 {
// 					 Objects[i].Set_ObjType(eNut);
// 					 obj_order = i+1;
// 					 Objects[i].Set_Order(obj_order);
// 				 }
// 				 else if((7 <= i) && (i <= 12))
// 				 {
// 					 Objects[i].Set_ObjType(eWasher);
// 					 obj_order = i-6;
// 					 Objects[i].Set_Order(obj_order);
// 				 }
// 				 else
// 				 {
// 					 Objects[i].Set_ObjType(eBolt);
// 					 obj_order = i-12;
// 					 Objects[i].Set_Order(obj_order);
// 				 }
// 
// 				 Objects[i].Set_Rotation((Objects[i].Get_ObjType() == eWasher)?0:(Objects[i].Get_ObjType() == eNut)?(rand()%60):(rand()%360));
// 				 //Objects[i].Set_Order(0);  //夾取順序初始化為0
//			 }
		 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: void Random_Set_Object_Position(void)  //隨機指定物件位置副函式
		 {
// 			 bool flag;
// 			 for(int i = 0; i < 18; i++)  
// 			 {	 
// 				 Set_Object_Position(&Objects[i]);
// 				 while(1)
// 				 {
// 					 flag = false;
// 					 for(int j = i-1; j >= 0; j--)
// 					 {
// 						 if(sqrt(pow(Objects[i].Get_x()-Objects[j].Get_x(), 2)+pow(Objects[i].Get_y()-Objects[j].Get_y(), 2)) <= (2.0*15.0))
// 						 {
// 							 flag = true;
// 							 break;
// 						 }
// 					 }
// 					 if(true == flag)
// 					 {
// 						 Set_Object_Position(&Objects[i]);
// 					 }
// 					 else
// 					 {
// 						 flag = false;
// 						 break;
// 					 }					
// 				 }
//			 }
		 }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: void Set_Object_Position(CObject* objs_data)  //隨機指定物件位置副函式
		 {
// 			 switch(objs_data->Get_ObjType())
// 			 {
// 			 case eNut:
// 				 objs_data->Set_Position((rand()%95) + 25.0, (rand()%210)+ 30.0);
// 				 break;
// 			 case eWasher:
// 				 objs_data->Set_Position((rand()%95) + 25.0, (rand()%210)+ 30.0);
// 				 break;
// 			 case eBolt:
// 				 objs_data->Set_Position((rand()%90) + 30.0, (rand()%220)+ 20.0);
// 				 break;
//			 }
		 }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: void Input_Data_to_DataGridView(CObject* data)  //將物件資料輸入至表單副函式
		 {
// 			 double tf_x, tf_y, tf_rtn;
// 			 tf_x = change_x(data->Get_x());
// 			 tf_y = change_y(data->Get_y());
// 			 tf_rtn = data->Get_Rotation();
// 			 data->Set_Tf_Position(tf_x,tf_y);
// 
// 
// 			 FinalTaskID = dataGridView1->RowCount-1;
// 			 NewRow = gcnew DataGridViewRow();
// 			 NewRow->CreateCells( dataGridView1 );
// 			 NewRow->Cells[1]->Value = Convert::ToInt32(data->Get_Order());
// 			 switch(data->Get_ObjType())
// 			 {
// 			 case teSelectObjType::eNut: NewRow->Cells[0]->Value = "Nut"; break;
// 			 case teSelectObjType::eWasher: NewRow->Cells[0]->Value = "Washer"; break;
// 			 case teSelectObjType::eBolt: NewRow->Cells[0]->Value = "Bolt"; break;
// 			 }
// 			 NewRow->Cells[2]->Value = Convert::ToInt32(data->Get_Rotation());
// 			 NewRow->Cells[3]->Value = Convert::ToInt32(data->Get_Tf_x());
// 			 NewRow->Cells[4]->Value = Convert::ToInt32(data->Get_Tf_y());
// 			 NewRow->Cells[5]->Value = Convert::ToInt32(data->Get_x());
// 			 NewRow->Cells[6]->Value = Convert::ToInt32(data->Get_y());
// 			 dataGridView1->Rows->Insert( FinalTaskID, NewRow );
// 			 dataGridView1->ClearSelection();
// 			 dataGridView1->Rows[FinalTaskID]->Selected = true;
// 			 dataGridView1->FirstDisplayedScrollingRowIndex = FinalTaskID;
		 }
/////////////////////////////////////////////////////////////////////////////////////////////
private: double change_x(double x)          //轉換x座標
		 {							
			 return ((206.0-x)/4.0);
		 }
/////////////////////////////////////////////////////////////////////////////////////////////
private: double change_y(double y)          //轉換y座標
		 {							
			 return ((y/4.0)+27.0);
		 }
/////////////////////////////////////////////////////////////////////////////////////////////


private: System::Void ReviseParameter_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Define_ePole_Box_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 double Pole_X,Pole_Y;
			 Pole_X = Convert::ToDouble(ePole_Box_X -> Text);
			 Pole_Y = Convert::ToDouble(ePole_Box_Y -> Text);
			 CVector3D	  Goal(Pole_X,Pole_Y,20);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void Define_eAssortingBolt_Box_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 double bolt_X,bolt_Y;
			 bolt_X = Convert::ToDouble(eAssortingBolt_Box_X -> Text);
			 bolt_Y = Convert::ToDouble(eAssortingBolt_Box_Y -> Text);
			 CVector3D	  Goal(bolt_X,bolt_Y,20);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void Define_eAssortingNutWasher_Box_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 double washer_X,washer_Y;
			 washer_X = Convert::ToDouble(eAssortingNutWasher_Box_X -> Text);
			 washer_Y = Convert::ToDouble(eAssortingNutWasher_Box_Y -> Text);
			 CVector3D	  Goal(washer_X,washer_Y,20);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void Define_eHole_Box_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 double hole_X,hole_Y;
			 hole_X = Convert::ToDouble(eHole_Box_X -> Text);
			 hole_Y = Convert::ToDouble(eHole_Box_Y -> Text);
			 CVector3D	  Goal(hole_X,hole_Y,20);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void Define_eBolt_Box_Click_1(System::Object^  sender, System::EventArgs^  e) 
		 {
			 double f_bolt_X,f_bolt_Y;
			 f_bolt_X = Convert::ToDouble(eBolt_Box_X -> Text);
			 f_bolt_Y = Convert::ToDouble(eBolt_Box_Y -> Text);
			 CVector3D	  Goal(f_bolt_X,f_bolt_Y,20);
			 tsEulerAngle Eular = {-90,0,0,0,0};
			 CIAArmInfo->ArmMove(PtP, Abs, Goal, Eular,20);
		 }
private: System::Void Confirm_Coordinate_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CIAArmInfo->AssortingBolt_Box_X = Convert::ToDouble(eAssortingBolt_Box_X->Text);
			 CIAArmInfo->AssortingBolt_Box_Y = Convert::ToDouble(eAssortingBolt_Box_Y->Text);
			 CIAArmInfo->AssortingNutWasher_Box_X = Convert::ToDouble(eAssortingNutWasher_Box_X->Text);
			 CIAArmInfo->AssortingNutWasher_Box_Y = Convert::ToDouble(eAssortingNutWasher_Box_Y->Text);
			 CIAArmInfo->Pole_Box_X = Convert::ToDouble(ePole_Box_X->Text);
			 CIAArmInfo->Pole_Box_Y = Convert::ToDouble(ePole_Box_Y->Text);
			 CIAArmInfo->Hole_Box_X = Convert::ToDouble(eHole_Box_X->Text);
			 CIAArmInfo->Hole_Box_Y = Convert::ToDouble(eHole_Box_Y->Text);
			 CIAArmInfo->Bolt_Box_X = Convert::ToDouble(eBolt_Box_X->Text);
			 CIAArmInfo->Bolt_Box_Y = Convert::ToDouble(eBolt_Box_Y->Text);
		 }

private: System::Void ckBox_BasicScore_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ;
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }


private: System::Void Btn_CameraConfirm_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 CIAArmInfo->Height_of_Camera = Convert::ToDouble(txtb_CameraHeight->Text);
		 }
};
}

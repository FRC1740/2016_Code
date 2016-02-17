#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/Autonomous/DoNothing.h"
#include "Commands/Autonomous/BasicAuto.h"
#include "Commands/Autonomous/DriveToGoal.h"
#include "Commands/Autonomous/EncoderTest.h"
#include "Commands/Autonomous/GyroTest.h"
#include "Commands/Drive_Modes/StandardTankDrive.h"
#include "Commands/Drive_Modes/ThreeAxisTankDrive.h"
#include "Commands/Drive_Modes/XBoxArcadeDrive.h"
#include "Commands/Drive_Modes/XBoxTankDrive.h"

class CommandBasedRobot : public IterativeRobot {
private:
	// TODO can i initialize a pointer to datalogger here?
	Command *autonomousCommand;
	Command *teleopcommand;
	LiveWindow *lw;
	Compressor *compressor;
	SendableChooser *drivemodechooser;
	SendableChooser *autonomouschooser;

	virtual void RobotInit()
	{
//		logger->Log("RobotInit()", STATUS_MESSAGE);
		CommandBase::init();

		drivemodechooser = new SendableChooser();
		drivemodechooser->AddDefault("Standard Tank Drive", new StandardTankDrive());
		drivemodechooser->AddObject("3 Axis Tank Drive", new ThreeAxisTankDrive());
		drivemodechooser->AddObject("XBox Tank Drive", new XBoxTankDrive());
		drivemodechooser->AddObject("XBox Arcade Drive", new XBoxArcadeDrive());
		SmartDashboard::PutData("Drive Mode", drivemodechooser);

//		->Log("added objects", VERBOSE_MESSAGE);
		autonomouschooser = new SendableChooser();
		autonomouschooser->AddDefault("Do Nothing", new DoNothing(15));
		autonomouschooser->AddObject("Basic Auto: Drive Forward", new BasicAuto());
		autonomouschooser->AddObject("Drive To Goal", new DriveToGoal());
		autonomouschooser->AddObject("Encoder Test", new EncoderTest(125));
		autonomouschooser->AddObject("Gyro Test", new GyroTest());
		SmartDashboard::PutData("Autonomous", autonomouschooser);

		lw = LiveWindow::GetInstance();
//		->Log("Starting robot!", VERBOSE_MESSAGE);
//		->Flush();
//		CameraServer::GetInstance()->SetQuality(100);
//		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

		compressor = new Compressor();
	}
	
	virtual void AutonomousInit()
	{
//		->Log("AutonomousInit()",STATUS_MESSAGE);
//		->Log("Starting Compressor", STATUS_MESSAGE);
		compressor->Start();
		autonomousCommand = (Command *) autonomouschooser->GetSelected();
		autonomousCommand->Start();
	}

	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TeleopInit()
	{
//		->Log("Entering TeleopInit()", STATUS_MESSAGE);
//		autonomousCommand->Cancel();
		teleopcommand = (Command *) drivemodechooser->GetSelected();
		teleopcommand->Start();
//		->End();
	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

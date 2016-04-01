#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/Autonomous/Forward.h"
#include "Commands/Autonomous/Reverse.h"
#include "Commands/Autonomous/DoNothing.h"
#include "Commands/Autonomous/EncoderTest.h"
#include "Commands/Autonomous/GyroTest.h"
#include "Commands/Autonomous/LowBar.h"
#include "Commands/Autonomous/RoughTerrain.h"
#include "Commands/Drive_Modes/StandardTankDrive.h"
#include "Commands/Drive_Modes/ThreeAxisTankDrive.h"
#include "Commands/Drive_Modes/XBoxArcadeDrive.h"
#include "Commands/Drive_Modes/XBoxTankDrive.h"
#include "Commands/Arm/ArmControl.h"
class CommandBasedRobot : public IterativeRobot {
private:
	// TODO can i initialize a pointer to datalogger here?
	Command *autonomousCommand;
	Command *teleopcommand;
	Command *armCommand;
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
		drivemodechooser->AddObject("XBox Arcade Drive", new XBoxArcadeDrive());
		drivemodechooser->AddObject("XBox Tank Drive", new XBoxTankDrive());
		SmartDashboard::PutData("Drive Mode", drivemodechooser);

//		->Log("added objects", VERBOSE_MESSAGE);
		autonomouschooser = new SendableChooser();
		autonomouschooser->AddDefault("Do Nothing", new DoNothing(15));
//		autonomouschooser->AddObject("Encoder Test", new EncoderTest(125));
//		autonomouschooser->AddObject("Gyro Test", new GyroTest());
		autonomouschooser->AddObject("Low Bar", new LowBar());
		autonomouschooser->AddObject("Rough Terrain, Rock Wall, etc.", new RoughTerrain(6000));
		SmartDashboard::PutData("Autonomous", autonomouschooser);

		lw = LiveWindow::GetInstance();
		// We don't have a datalogger object yet.
		//datalogger->Log("Starting robot!", VERBOSE_MESSAGE);

		// No compressor on this 'bot
//		compressor = new Compressor();
		CameraServer::GetInstance()->SetQuality(100);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	}
	
	virtual void AutonomousInit()
	{
//		->Log("AutonomousInit()",STATUS_MESSAGE);
//		->Log("Starting Compressor", STATUS_MESSAGE);
//		compressor->Start();
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
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
		// The correct way to do the following is through the Subsystem's Default Command
//		armCommand = new ArmControl();
//		armCommand->Start();
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

#include "../../Commands/Autonomous/LowBar.h"
#include "../../Commands/Autonomous/Forward.h"
#include "../../Commands/Autonomous/Reverse.h"
#include "../../Commands/Autonomous/Pause.h"
#include "../Drivetrain/Move.h"
#include "../Arm/Down.h"
#include "RoughTerrain.h"

LowBar::LowBar()
{
	// AddSequential(new Down()); // No more arm on the bot
	AddSequential(new Forward(3000));
	AddSequential(new Pause(200));
	AddSequential(new Reverse(3000));
}

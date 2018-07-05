//============================================================================
// Name        : main.cpp
// Author      : Thomas Kummer
//============================================================================

#include <iostream>
#include "Definitions.h"
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <math.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/times.h>
#include <sys/time.h>
#include <chrono>
#include <thread>
#include "Engine.cpp"

enum mode { profilePosition, position, interpolatedPosition };


int main(int argc, char** argv)
{
    
    Engine maxonMotor;
    maxonMotor.setProtocolStackSettings();
    maxonMotor.disableState();
    maxonMotor.addMotor();
    maxonMotor.addSensors();
    maxonMotor.setRegulatorGains();

    int mode (profilePosition);
    
    switch (mode)
    {
        case profilePosition:
            maxonMotor.activatePositionMode();
            maxonMotor.runPositionMode();
            break;
            
        case position:
            maxonMotor.activateProfilePositionMode();
            maxonMotor.runProfilePositionMode();
            break;

        case interpolatedPosition:
            maxonMotor.activateInterpolatedPositionMode();
            maxonMotor.runInterpolatedPositionMode();
            break;

        default:
            break;
    }
    
}

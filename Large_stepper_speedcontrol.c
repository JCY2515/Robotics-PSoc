//Wong Chung Yin Lab4 Large Stepper Motor for Developing Speed Control
#include "project.h"

int main(void)
{
    int TargetRotationSpeed = 100; // Rotation Per Minute
    int MicroStepSize = 8;
    int BaseStepCountperRevolution = 360.0/1.8;
    uint64_t MicroSecondDelayTime =0; //for the μs time delay between pulses
    uint64_t StepCount=0; //for the number of steps taken in a revolution
    int AdjustedStepsPerRevolution;
    float CalculatedRPM;
    
    AdjustedStepsPerRevolution = BaseStepCountperRevolution*MicroStepSize;
    MicroSecondDelayTime = (1.0/(float)TargetRotationSpeed)*(1.0/(float)AdjustedStepsPerRevolution)*(60.0/1.0)*(1000.0/1)*(1000.0/1.0)*(1.0/2.0);
    Enable_Write(0);
    Direction_Write(0);
    for(;;)
    {
        Pulse_Write(1);
        CyDelayUs(MicroSecondDelayTime);
        Pulse_Write(0);
        CyDelayUs(MicroSecondDelayTime);
    }
}


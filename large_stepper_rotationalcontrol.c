//Wong Chung Yin Lab4 Large Stepper Motor for Developing Rotational Control
#include "project.h"

int main(void)
{
    float TargetRotationalAngle = 90.0;
    int TargetRotationSpeed = 120; // Rotation Per Minute
    int MicroStepSize = 8;
    int BaseStepCountperRevolution = 360.0/1.8;
    uint64_t MicroSecondDelayTime = 0; //for the μs time delay between pulses
    uint64_t StepCount = 0; //for the number of steps taken in a revolution
    int AdjustedStepsPerRevolution = 0;
    float StepsNeeded = 0.0;
    
    AdjustedStepsPerRevolution = BaseStepCountperRevolution*MicroStepSize;
    MicroSecondDelayTime = (1.0/(float)TargetRotationSpeed)*(1.0/(float)AdjustedStepsPerRevolution)*(60.0/1.0)*(1000.0/1)*(1000.0/1.0)*(1.0/2.0);
    StepsNeeded = (TargetRotationalAngle/360.0)*AdjustedStepsPerRevolution;
    Enable_Write(0);
    Direction_Write(0);
    CyDelay(5);
    for(;;)
    {   
        while(StepCount < StepsNeeded)
        {
            Pulse_Write(1);
            CyDelayUs(MicroSecondDelayTime);
            Pulse_Write(0);
            CyDelayUs(MicroSecondDelayTime);
            Pulse_Write(1);
            CyDelayUs(MicroSecondDelayTime);
            Pulse_Write(0);
            CyDelayUs(MicroSecondDelayTime);
            StepCount+=2;
        }
        CyDelay(5000);
        Direction_Write(1);
        StepCount=0;
        while(StepCount < StepsNeeded)
        {
            Pulse_Write(1);
            CyDelayUs(MicroSecondDelayTime);
            Pulse_Write(0);
            CyDelayUs(MicroSecondDelayTime);
            Pulse_Write(1);
            CyDelayUs(MicroSecondDelayTime);
            Pulse_Write(0);
            CyDelayUs(MicroSecondDelayTime);
            StepCount+=2;
        }
        CyDelay(5000);
        Direction_Write(0);
        StepCount=0;
    }
}


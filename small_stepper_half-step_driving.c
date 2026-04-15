//Wong Chung Yin Lab5 Small Stepper Motor for the oscillating rotation distance-controlled code using the half-step driving technique
#include "project.h"

int main(void)
{
    int delay = 1;
    int Direction = 1; //clockwise(1) or counterclockwise (0)
    float angle=360.0;//desired angle turn in degrees
    uint64_t StepCount = 0; //for the number of steps taken in a revolution
    float StepsNeeded = angle/360.0*2048;
    if(Direction==0)
    {
        for(StepCount = 0;StepCount<StepsNeeded;StepCount+=4)
        {
            A_Write(0);
            B_Write(1);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);

            A_Write(1);
            B_Write(1);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(0);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(0);
            C_Write(0);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(0);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(1);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(1);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(1);
            C_Write(1);
            D_Write(0);
            CyDelay(delay);
        }
        for(StepCount = 0;StepCount<StepsNeeded;StepCount+=4)
        {
            A_Write(0);
            B_Write(1);
            C_Write(1);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(1);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(1);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(0);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(0);
            C_Write(0);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(0);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(1);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(1);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
        }
    }
    else
    {
           for(StepCount = 0;StepCount<StepsNeeded;StepCount+=4)
        {
            A_Write(0);
            B_Write(1);
            C_Write(1);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(1);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(1);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(0);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(0);
            C_Write(0);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(0);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(1);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(1);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
        }
        for(StepCount = 0;StepCount<StepsNeeded;StepCount+=4)
        {
            A_Write(0);
            B_Write(1);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);

            A_Write(1);
            B_Write(1);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(0);
            C_Write(0);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(1);
            B_Write(0);
            C_Write(0);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(0);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(1);
            D_Write(1);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(0);
            C_Write(1);
            D_Write(0);
            CyDelay(delay);
            
            A_Write(0);
            B_Write(1);
            C_Write(1);
            D_Write(0);
            CyDelay(delay);
        }
    }
}


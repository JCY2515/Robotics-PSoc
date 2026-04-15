//Wong Chung Yin Lab5 Small Stepper Motor for the rotation velocity-controlled code using the wave-driving technique
#include "project.h"

int main(void)
{
    float velocity = 10.0; //Desired motor speed in rpm
    float stepAngleSize = 360.0/2048.0;
    int desiredAngle;
    int delay = 1.0/((velocity)*(1.0/60.0)*(1.0/1000.0)*(360.0/1.0)*(1.0/stepAngleSize));
    for(;;)
    {
        A_Write(1);
        B_Write(0);
        C_Write(0);
        D_Write(0);
        CyDelay(delay);

        A_Write(0);
        B_Write(1);
        C_Write(0);
        D_Write(0);
        CyDelay(delay);
        
        A_Write(0);
        B_Write(0);
        C_Write(1);
        D_Write(0);
        CyDelay(delay);
        
        A_Write(0);
        B_Write(0);
        C_Write(0);
        D_Write(1);
        CyDelay(delay);
    }
}


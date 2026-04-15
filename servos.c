#include "project.h"
#include "math.h"

int Theta1(float Angle)
{
    int Compare;
    int min_comp = 1150;
    int max_comp = 6800;
    int min_angle = 0;
    int max_angle = 180;
    Compare = (max_comp - min_comp) / (max_angle - min_angle) * (Angle - min_angle) + min_comp;
    return Compare;
}

int Theta2(float Angle)
{
    int Compare;
    int min_comp = 1250;
    int max_comp = 6950;
    int min_angle = -90;
    int max_angle = 90;
    Compare = (max_comp - min_comp) / (max_angle - min_angle) * (Angle - min_angle) + min_comp;
    return Compare;
}

int main(void)
{
    float X=6.0; //Desired X position of the end-effector in cm
    float Y=10.0; //Desried Y position of the end-effector in cm
    float r1=0.0;
    float phi1=0.0;
    float phi2=0.0;
    float phi3=0.0;
    float a2=7.0;
    float a4=8.0;
    float T1=0.0; //T1 is theta 1 in radians
    float T2=0.0; //T2 is theta 2 in radians
    
    r1=sqrt(X*X+Y*Y);//Eq. 1
    phi1=acos(((a4*a4)-(a2*a2)-(r1*r1))/(-2.0*a2*r1)); //Eq. 2
    phi2=atan(Y/X); //Eq. 3
    T1=phi2-phi1;
    phi3=acos(((r1*r1)-(a2*a2)-(a4*a4))/(-2.0*a2*a4)); //Eq. 5
    T2=3.14159-phi3; //Eq. 6
    
    PWM_1_Start();
    for(;;)
    {
        PWM_1_WriteCompare1(Theta1((T1/3.14159)*180.0)); //Send servo 1 to clockwise position
        PWM_1_WriteCompare2(Theta2((T2/3.14159)*180.0)); //Send servo 2 to clockwise position
        CyDelay(2000);
        
//        PWM_1_WriteCompare1(Theta1(180.0)); // Send servo 1 to counterclockwise position
//        CyDelay(2000);
//        
//        PWM_1_WriteCompare2(Theta2(-90.0)); //Send servo 2 to clockwise position
//        CyDelay(2000);
//        PWM_1_WriteCompare2(Theta2(90.0)); // Send servo 2 to counterclockwise position
//        CyDelay(2000);
    }
}


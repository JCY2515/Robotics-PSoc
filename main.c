#include "project.h"
#include "math.h"

int Theta1(float Angle)
{
    int Compare;
    int min_comp = 1050;
    int max_comp = 6825;
    int min_angle = 0;
    int max_angle = 180;
    Compare = (max_comp - min_comp) / (max_angle - min_angle) * (Angle - min_angle) + min_comp;
    return Compare;
}

int Theta2(float Angle)
{
    int Compare;
    int min_comp = 1250;
    int max_comp = 6900;
    int min_angle = 0;
    int max_angle = 180;
    Compare = (max_comp - min_comp) / (max_angle - min_angle) * (Angle - min_angle) + min_comp;
    return Compare;
}

int main(void)
{
    float Angle1;
    float incrementTheta1;
    float Theta1dot; //Degree per second velocity of the first servo
    
    float Angle2;
    float incrementTheta2;
    float Theta2dot; //Degree per second velocity of the second servo
    
    float Xdot=1.0; //cm/s
    float Ydot=1.0;
    
    float multiplier;
    float J11inv;
    float J12inv;
    float J21inv;
    float J22inv;
    float J11;
    float J12;
    float J21;
    float J22;
    
    float a2=5.0;
    float a4=6.5;
    
    Servos_Start();
    Angle1=0.0;
    Angle2=90.0;
    Servos_WriteCompare1(Theta1(Angle1));
    Servos_WriteCompare2(Theta2(Angle2));
    CyDelay(3000);
    
    while (Angle1<=180.0 && Angle1>=0.0 && Angle2<=180.0 && Angle2>=0.0)
    {
        //Convert to Radians
        Angle1=(Angle1/180.0)*3.14159;
        Angle2=(Angle2/180.0)*3.14159;
        
        J11=-a4*sin(Angle1)*cos(Angle2)-a4*cos(Angle1)*sin(Angle2)-a2*sin(Angle1);
        J21=a4*cos(Angle1)*cos(Angle2)-a4*sin(Angle1)*sin(Angle2)+a2*cos(Angle1);
        J12=-a4*sin(Angle1)*cos(Angle2)-a4*cos(Angle1)*sin(Angle2);
        J22=a4*cos(Angle1)*cos(Angle2)-a4*sin(Angle1)*sin(Angle2);
        
        multiplier=1.0/(J11*J22-J12*J21);
        
        J11inv= multiplier*J22;
        J21inv= multiplier*(-J21);
        J12inv = multiplier*(-J12);
        J22inv = multiplier*J11;
        
        Theta1dot=J11inv*Xdot+J12inv*Ydot;
        incrementTheta1=Theta1dot/100.0;
        Theta2dot=J21inv*Xdot+J22inv*Ydot;
        incrementTheta2=Theta2dot/100.0;
        
        Angle1=Angle1+incrementTheta1;
        Angle2=Angle2+incrementTheta2;
        
        //Convert back to Degrees
        Angle1=(Angle1/3.14159)*180.0;
        Angle2=(Angle2/3.14159)*180.0;
        
        Servos_WriteCompare1(Theta1(Angle1));
        Servos_WriteCompare2(Theta2(Angle2));
        CyDelay(10);
    }
}


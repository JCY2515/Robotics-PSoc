#include "project.h"

int ThetaOne(float Angle) //new function to take a first angle and give a compare value that is tuned to the first servo.
{
    int Compare;
    int min_comp = 1100; // 1500 for the starting point for the minimal compare value
    int max_comp = 6800; // 6900 for the starting point for the maximum compare value
    int min_angle = 0; // minimal servo angle at the minimal compare value
    int max_angle = 180; //maximum servo angle at the maximum compare value
    Compare=((max_comp-min_comp)/(max_angle-min_angle))*(Angle-min_angle)+min_comp; // linear equation
    return Compare;
}

int ThetaTwo(float Angle) //new function to take a second angle and give a compare value that is tuned to the second servo.
{
    int Compare;
    int min_comp = 1250; //these are variables, and calculations are separate from the other functions.
    int max_comp = 6950;
    int min_angle = 0;
    int max_angle = 180;
    Compare=((max_comp-min_comp)/(max_angle-min_angle))*(Angle-min_angle)+min_comp; // linear equation
    return Compare;
}

int ThetaThree(float Angle) //new function to take a three angle and give a compare value that is tuned the third servo.
{
    int Compare;
    int min_comp = 1700; // these are variables, and calculations are separate from the other functions.
    int max_comp = 6900;
    int min_angle = 0;
    int max_angle = 180;
    Compare=((max_comp-min_comp)/(max_angle-min_angle))*(Angle-min_angle)+min_comp; // linear equation
    return Compare;
}

int main(void) //This is a function called "main," which can return an int variable, and it does not expect any input variables.
{
    float TargetAngle_1 = 45.0;
    float TargetAngle_2 = 45.0;
    float TargetAngle_3 = 45.0;
    PWM_1_Start();
    PWM_2_Start();
    for(;;)
    {
        PWM_1_WriteCompare1(ThetaOne(0.0)); //Send Servo 1 to "0" degrees
        PWM_1_WriteCompare2(ThetaTwo(0.0)); //Send Servo 2 to "0" degrees
        PWM_2_WriteCompare(ThetaThree(0.0)); //Send Servo 3 to "0" degrees
        CyDelay(2000);
        PWM_1_WriteCompare1(ThetaOne(TargetAngle_1)); //Send Servo 1 to input angle in degrees
        PWM_1_WriteCompare2(ThetaTwo(TargetAngle_2)); //Send Servo 2 to input angle in degrees
        PWM_2_WriteCompare(ThetaThree(TargetAngle_3)); //Send Servo 3 to input angle in degrees
        CyDelay(20000);
    }
}

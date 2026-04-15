//Chung Yin Wong
#include "project.h"
#include <math.h>

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
    int min_comp = 1050; //these are variables, and calculations are separate from the other functions.
    int max_comp = 6800;
    int min_angle = -90;
    int max_angle = 90;
    Compare=((max_comp-min_comp)/(max_angle-min_angle))*(Angle-min_angle)+min_comp; // linear equation
    return Compare;
}

int main(void)
{
    PWM_1_Start();

    // ===== Variables =====
    float AngleOne;                 // Servo 1 current angle (deg)
    float AngleTwo;                 // Servo 2 current angle (deg)

    float increment_Theta_One = 0.0;   // Servo 1 step increment (deg per 10ms step)
    float increment_Theta_Two = 0.0;   // Servo 2 step increment (deg per 10ms step)

    float ThetaOneDot;              // Servo 1 angular velocity (deg/s)
    float ThetaTwoDot;              // Servo 2 angular velocity (deg/s)

    // NOTE: These angle combos may work but draw off the base:
    //   - angle1 = 120.0, angle2 = 45.0 xdot = 0.5 and ydot = 0.0 -> horzontal line    or    xdot = 0.5 and ydot = 0.5 -> 45 degree line 
    //   - angle1 = 45.0,  angle2 = -90.0  xdot = 0.0 and ydot = 0.5 -> vertical line

    // Start position for "45 movement" (Servo 2 range: +90 to -90 deg)
    float AngleOne_Start = 45.0;    // Starting angle for joint 1 (deg)
    float AngleTwo_Start = -90.0;  // Starting angle for joint 2 (deg)

    // End-effector velocities
    float xdot = 0.0;              // cm/s
    float ydot = 0.5;              // cm/s

    // Link lengths
    float a2 = 5.5;  // cm
    float a4 = 9.5;  // cm

    // Jacobian elements
    float J11, J12, J21, J22;

    // Inverse Jacobian elements
    float Inv_Divider;
    float J11_inv, J12_inv, J21_inv, J22_inv;

    // ===== Move arm to start position =====
    PWM_1_WriteCompare1(ThetaOne(AngleOne_Start));
    PWM_1_WriteCompare2(ThetaTwo(AngleTwo_Start));
    CyDelay(3000);

    // Set initial joint angles
    AngleOne = AngleOne_Start;
    AngleTwo = AngleTwo_Start;

    float time = 0.0; // seconds

    while (time < 7.0)
    {
        // Update joint angles by incremental step
        AngleOne = AngleOne + increment_Theta_One;
        AngleTwo = AngleTwo + increment_Theta_Two;

        // Convert angles to radians for Jacobian math
        float rad1 = (AngleOne / 180.0) * 3.14159;
        float rad2 = (AngleTwo / 180.0) * 3.14159;

        // ===== Jacobian matrix (fill in formulas) =====
        J11 = -a2*sin(rad1)-a4*sin(rad1 + rad2);
        J12 = -a4*sin(rad1 + rad2);
        J21 = a2*cos(rad1)+a4*cos(rad1 + rad2);
        J22 = a4*cos(rad1 + rad2);

        // ===== Inverse Jacobian =====
        Inv_Divider = 1.0 / ((J11 * J22) - (J12 * J21));
        J11_inv = Inv_Divider * J22;
        J12_inv = Inv_Divider * (-J12);
        J21_inv = Inv_Divider * (-J21);
        J22_inv = Inv_Divider * J11;

        // ===== Joint angular velocities (rad/s) =====
        ThetaOneDot = (J11_inv * xdot) + (J12_inv * ydot);
        ThetaTwoDot = (J21_inv * xdot) + (J22_inv * ydot);

        // Convert velocities to deg/s
        ThetaOneDot = (ThetaOneDot / 3.14159) * 180.0;
        ThetaTwoDot = (ThetaTwoDot / 3.14159) * 180.0;

        // Convert velocity (deg/s) -> per-step increment (deg per 10ms)
        // 10ms = 0.01s, so increment = deg/s * 0.01 = deg/s / 100
        increment_Theta_One = ThetaOneDot / 100.0;
        increment_Theta_Two = ThetaTwoDot / 100.0;

        // Send angles (deg) to servos
        PWM_1_WriteCompare1(ThetaOne(AngleOne)); // Servo 1
        PWM_1_WriteCompare2(ThetaTwo(AngleTwo)); // Servo 2

        CyDelay(10);
        time = time + 0.01f;
    }
}


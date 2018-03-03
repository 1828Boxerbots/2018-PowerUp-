#ifndef FourBar_H
#define FourBar_H

#include <WPILib.h>

#include <array>

#include <Commands/Subsystem.h>

#include <AnalogInput.h>
#include <PIDController.h>
#include <Spark.h>
#include <XboxController.h>

#include "RobotMap.h"

using namespace frc;
using namespace std;

class FourBar : public Subsystem
{
public:
	FourBar();
	void InitDefaultCommand();
	void Movement(XboxController* controller);
	void SetInversions();
	void EnablePIDController();
	void PIDControllerInit();
	void SetAngle(int setpoint);

	static constexpr int SETPOINTSNUMBER = 3;
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark m_leftFourBarMotor {LEFT_FOUR_BAR_MOTOR_PORT};
	Spark m_rightFourBarMotor {RIGHT_FOUR_BAR_MOTOR_PORT};

	AnalogInput m_pot {FOUR_BAR_POTENTIOMETER_PORT};

	/*
	 * The values for a PID need to be negative on inverted motors and
	 * positive of inverted motors.
	 * kP is the proportional Gain
	 * kI is the proportional Integral
	 * kD is the proportional Derivative
	 */
	PIDController m_leftGantryPID {kP, kI, kD, &m_pot, &m_leftFourBarMotor};
	PIDController m_rightGantryPID {kP, kI, kD, &m_pot, &m_rightFourBarMotor};

	static constexpr double kP = -5.0;
	static constexpr double kI = -0.02;
	static constexpr double kD = -2.0;

	int m_index = 0;
	bool m_previousValue = false;

	static constexpr array<double, SETPOINTSNUMBER> kSetPoints = {0.0, 2.6, 4.3};
};

#endif  // FourBar_H

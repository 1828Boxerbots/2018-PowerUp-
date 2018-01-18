#ifndef Grip_H
#define Grip_H

#include <Commands/Subsystem.h>

class Grip : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Grip();
	void InitDefaultCommand();
};

#endif  // Grip_H

#ifndef Drive_H
#define Drive_H

#include <Commands/Subsystem.h>

class Drive : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Drive();
	void InitDefaultCommand();
};

#endif  // Drive_H

#ifndef BlankSubsystem_H
#define BlankSubsystem_H

#include <Commands/Subsystem.h>

class BlankSubsystem : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	BlankSubsystem();
	void InitDefaultCommand();
};

#endif  // BlankSubsystem_H

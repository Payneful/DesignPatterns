#pragma once
#include <list>
#include "bird.h"

using namespace std;

class ApplyImpulse {
public:
	virtual void Impulse(Bird bird) = 0;
};

// ApplyTurn is the only class with a private function, not public.
class ApplyTurn {
private:
	void impulse(Bird);
};
class ApplyInertia : public ApplyImpulse {
public:
	void impulse(Bird bird);
};
class ApplyGravity : public ApplyImpulse {
public:
	void impulse(Bird bird);
};
class ApplyBuoyancy : public ApplyImpulse {
public:
	void impulse(Bird bird);
};
class ApplyDrag : public ApplyImpulse {
public:
	void impulse(Bird bird);
};
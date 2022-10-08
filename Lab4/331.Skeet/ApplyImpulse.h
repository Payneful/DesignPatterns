#pragma once
#include <list>
#include "point.h"
#include "bird.h"


using namespace std;

// For circular dependencies
class Bird;

class ApplyImpulse
{
public:
	virtual void impulse(Bird &bird) = 0;
};

// ApplyTurn is the only class with a private function, not public.
class ApplyTurn : public ApplyImpulse
{
private:
	void impulse(Bird &bird);
};

class ApplyInertia : public ApplyImpulse
{
private:
	void impulse(Bird &bird);
};

class ApplyGravity : public ApplyImpulse
{
private:
	void impulse(Bird &bird);
};

class ApplyBuoyancy : public ApplyImpulse
{
private:
	void impulse(Bird &bird);
};

class ApplyDrag : public ApplyImpulse
{
private:
	void impulse(Bird &ird);
};

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
public:
	void impulse(Bird &bird);
};

class ApplyInertia : public ApplyImpulse
{
public:
	void impulse(Bird &bird);
};

class ApplyGravity : public ApplyImpulse
{
public:
	void impulse(Bird &bird);
};

class ApplyBuoyancy : public ApplyImpulse
{
public:
	void impulse(Bird &bird);
};

class ApplyDrag : public ApplyImpulse
{
public:
	void impulse(Bird &ird);
};

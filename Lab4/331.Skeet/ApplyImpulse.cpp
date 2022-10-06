#include <list>
#include "bird.h"
using namespace std;


class ApplyImpulse {
public:
	virtual void applyImpulse(Bird bird) = 0;
};

class ApplyInertia : public ApplyImpulse {
public:
	void impulse(Bird bird) {
		Velocity v = bird.getVelocity();
		Point p = bird.getPosition();
		p += v;
		bird.operator=(p);
	}
};
class ApplyGravity : public ApplyImpulse {
public:
	// setVelocity does not exist
	void impulse(Bird bird) {
		Velocity v = bird.getVelocity();
		v.addDy(-0.04);
		//bird.setVelocity(v)
	}
};
class ApplyBuoyancy : public ApplyImpulse {
public:
	// setVelocity does not exist
	void impulse(Bird bird) {
		Velocity v = bird.getVelocity();
		v.addDy(0.05);
		//bird.setVelocity(v);
	}
};
class ApplyDrag : public ApplyImpulse {
public:
	// setVelocity and getDirection do not exist
	void impulse(Bird bird) {
		Velocity v = bird.getVelocity();
		//bird.setVelocity(v.getSpeed() * 0.995, v.getDirection());
	}
};
class ApplyTurn : public ApplyImpulse {
private:
	// setVelocity does not exist
	void impulse(Bird bird) {
		if (bird.randomInt(0, 15) == 0)
		{
			Velocity v = bird.getVelocity();
			v.addDy(v.getDy() + bird.randomInt(-1.5, 1.5));
			v.addDx(v.getDx() + bird.randomInt(-1.5, 1.5));
			//bird.setVelocity(v);
		}
	}
};
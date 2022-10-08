#include "ApplyImpulse.h"
#include <cassert>
using namespace std;

/***************************************************************/
/***************************************************************/
/*                             MISC.                           */
/***************************************************************/
/***************************************************************/


/******************************************************************
 * RANDOM
 * This functions generate a random number.
 ****************************************************************/
int randomInteger(int min, int max)
{
   //assert(min < max);
   int num = (rand() % (max - min)) + min;
   //assert(min <= num && num <= max);
   return num;
}


void ApplyInertia::impulse(Bird &bird) {
		Velocity v = bird.getVelocity();
		Point p = bird.getPosition();
		p += v;
		bird = p;
	}

void ApplyGravity::impulse(Bird &bird) {
		Velocity v = bird.getVelocity();
		v.addDy(-0.04);
		bird = v;
	}

void ApplyBuoyancy::impulse(Bird &bird) {
		Velocity v = bird.getVelocity();
		v.addDy(0.05);
		bird = v;
	}

void ApplyDrag::impulse(Bird &bird) {
		Velocity v = bird.getVelocity();
   bird = (static_cast<void>(v.getSpeed() * 0.995), bird.getVelocity());
	}

void ApplyTurn::impulse(Bird &bird) {
		if (randomInteger(0, 15) == 0)
		{
			Velocity v = bird.getVelocity();
			v.addDy(v.getDy() + randomInteger(-1.5, 1.5));
			v.addDx(v.getDx() + randomInteger(-1.5, 1.5));
			bird = v;
		}
	}


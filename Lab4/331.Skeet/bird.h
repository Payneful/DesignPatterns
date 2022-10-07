/***********************************************************************
 * Header File:
 *    Bird : Everything that can be shot
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that moves across the screen to be shot
 ************************************************************************/

#pragma once
#include "point.h"
#include <cassert>

class Advance;

/**********************
 * BIRD
 * Everything that can be shot
 **********************/
class Bird
{
protected:
   static Point dimensions; // size of the screen
   Point pt;                  // position of the flyer
   Velocity v;                // velocity of the flyer
   double radius;             // the size (radius) of the flyer
   bool dead;                 // is this flyer dead?
   int points;                // how many points is this worth?
   Advance* adv;
   
public:
   Bird() : dead(false), points(0), radius(1.0) { adv = nullptr; }
   
   // setters
   void operator=(const Point    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void kill()                          { dead = true; }
   void adjustVelocity(float amount)    { v *= amount; }
   void adjustPosition(Velocity vel)    { pt += vel;   }

   // getters
   bool isDead()           const { return dead;   }
   Point getPosition()     const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints()         const { return points; }
   bool isOutOfBounds()    const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }

   // special functions
   virtual void draw() = 0;
   virtual void advance() = 0;
};

/*********************************************
 * STANDARD
 * A standard bird: slows down, flies in a straight line
 *********************************************/
class Standard : public Bird
{
public:
    Standard(double radius = 25.0, double speed = 5.0, int points = 10);
    void draw();
    void advance();
};

/*********************************************
 * FLOATER
 * A bird that floats like a balloon: flies up and really slows down
 *********************************************/
class Floater : public Bird
{
public:
    Floater(double radius = 30.0, double speed = 5.0, int points = 15);
    void draw();
    void advance();
};

/*********************************************
 * CRAZY
 * A crazy flying object: randomly changes direction
 *********************************************/
class Crazy : public Bird
{
public:
    Crazy(double radius = 30.0, double speed = 4.5, int points = 30);
    void draw();
    void advance();
};

/*********************************************
 * SINKER
 * A sinker bird: honors gravity
 *********************************************/
class Sinker : public Bird
{
public:
    Sinker(double radius = 30.0, double speed = 4.5, int points = 20);
    void draw();
    void advance();
};

/*********************************************
 * Advance
 * Moves the birds
 *********************************************/
class Advance
{
public:
   virtual void advance(Bird &bird, int points) = 0;
};

class Inertia : public Advance
{
public:
   virtual ~Inertia() {};

   void advance(Bird &bird, int points)
   {
      bird.adjustVelocity(0.995);

      bird.adjustPosition(bird.getVelocity());

      if (bird.isOutOfBounds())
      {
         bird.kill();
         points *= -1; // points go negative when it is missed!
      }
   };
};

class Gravity : public Advance
{
public:
   virtual ~Gravity() {};

   void advance(Bird& bird, int points)
   {
      // gravity
      bird.getVelocity().addDy(-0.07);

      // inertia
      bird.adjustPosition(bird.getVelocity());

      if (bird.isOutOfBounds())
      {
         bird.kill();
         points *= -1; // points go negative when it is missed!
      }
   };
};


class Buoyancy : public Advance
{
public:
   virtual ~Buoyancy() {};

   void advance(Bird& bird, int points)
   {
      // large amount of drag
      bird.adjustVelocity(0.990);

      // inertia
      bird.adjustPosition(bird.getVelocity());

      // anti-gravity
      bird.getVelocity().addDy(0.05);

      // out of bounds checker
      if (bird.isOutOfBounds())
      {
         bird.kill();
         points *= -1; // points go negative when it is missed!
      }
   };
};


class Chaos : public Advance
{
public:
   virtual ~Chaos() {};

   double randomFloat(double min, double max)
   {
      assert(min <= max);
      double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
      assert(min <= num && num <= max);
      return num;
   }

   int randomInt(int min, int max)
   {
      assert(min < max);
      int num = (rand() % (max - min)) + min;
      assert(min <= num && num <= max);
      return num;
   }

   void advance(Bird &bird, int points)
   {
      // erratic turns eery half a second or so
      if (randomInt(0, 15) == 0)
      {
         bird.getVelocity().addDy(randomFloat(-1.5, 1.5));
         bird.getVelocity().addDx(randomFloat(-1.5, 1.5));
      }

      // inertia
      bird.adjustPosition(bird.getVelocity());

      // out of bounds checker
      if (bird.isOutOfBounds())
      {
         bird.kill();
         points *= -1; // points go negative when it is missed!
      }
   };
};

/***********************************************************************
 * Header File:
 *    Bird : Everything that can be shot
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Stuff that moves across the screen to be shot
 ************************************************************************/

#pragma once
#include "ApplyImpulse.h"
#include <list>
#include "point.h"

// For circular dependencies
class ApplyImpulse;

/**********************
 * BIRD
 * Everything that can be shot
 **********************/
class Bird
{
protected:
   static Point dimensions;               // size of the screen
   Point pt;                              // position of the flyer
   Velocity v;                            // velocity of the flyer
   double radius;                         // the size (radius) of the flyer
   bool dead;                             // is this flyer dead?
   int points;                            // how many points is this worth?
   std::list<ApplyImpulse*> impulses;     // Impulses
   
   
public:
   Bird() : dead(false), points(0), radius(1.0) { }
   
   // setters
   void operator=(const Point    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void kill()                          { dead = true; }
   void advance();

   // getters
   bool isDead()           const { return dead;   }
   Point getPosition()     const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints() const { return points; }
   std::list<ApplyImpulse*> getImpulses() const { return impulses; }
   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }

   // special functions
   virtual void draw() = 0;
   
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

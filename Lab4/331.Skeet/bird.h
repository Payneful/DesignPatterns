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
#include "Mediator.h"

class Colleague;              // For circular dependencies

/**********************
 * BIRD
 * Everything that can be shot
 **********************/
class Bird
{
protected:
   static Point dimensions;   // size of the screen
   Point pt;                  // position of the flyer
   Velocity v;                // velocity of the flyer
   double radius;             // the size (radius) of the flyer
   bool dead;                 // is this flyer dead?
   int points;                // how many points is this worth?
   BirdColleague colleague;
   
public:
   Bird() : dead(false), points(0), radius(1.0) { colleague.setColleague(this); }
   
   // setters
   void operator=(const Point    & rhs) { pt = rhs;    }
   void operator=(const Velocity & rhs) { v = rhs;     }
   void kill()                          { dead = true; }

   // getters
   bool isDead()           const { return dead;   }
   Point getPosition()     const { return pt;     }
   Velocity getVelocity()  const { return v;      }
   double getRadius()      const { return radius; }
   int getPoints() const { return points; }
   bool isOutOfBounds() const
   {
      return (pt.getX() < -radius || pt.getX() >= dimensions.getX() + radius ||
              pt.getY() < -radius || pt.getY() >= dimensions.getY() + radius);
   }
   
   void wasShot(Mediator* mediator)
   {
      kill();
      colleague.enroll(mediator);
      colleague.wasShot();
   }

   // special functions
   virtual void draw() = 0;
   virtual void advance(Mediator* mediator) = 0;
   
protected:
   void outOfBoundsChecker()
   {
      // out of bounds checker
      if (isOutOfBounds())
      {
         kill();
         points *= -1; // points go negative when it is missed!
         colleague.wentOutOfBounds();
      }
   }
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
    void advance(Mediator* mediator);
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
    void advance(Mediator* mediator);
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
    void advance(Mediator* mediator);
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
    void advance(Mediator* mediator);
};

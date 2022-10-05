//
//  Mediator.h
//  Serve as a hub for messages between HitRatio, Status, Bullet, and Bird.
//  Created by Anne George on 10/21/22.
//

#ifndef Mediator_h
#define Mediator_h

#include "bird.h"
#include "vector"
#pragma once

class Colleague;
struct Message;
class Bird;    // For circular dependencies

class Mediator
{
protected:
   std::vector<Colleague*> colleagues;
   
public:
   void notify(const Message & message);
   void enroll(const Colleague & enrolle);
   void unenroll(const Colleague & enrolle);
};

struct Message
{
   enum type {Bullet_fired, Bird_died};
   int value;
};

class Colleague
{
protected:
   Mediator mediator; //pointer?
   
public:
   virtual void notify(const Message & message) = 0;
   void enroll(const Mediator & mediator);
   void unenroll(const Mediator & mediator);
};

class BirdColleague : public Colleague
{
private:
   int status; //not sure the data type yet.
   Bird * pBird;
   
public:
   void notify(const Message & message);
   void wentOutOfBounds();
   void wasShot();
};

#endif /* Mediator_h */

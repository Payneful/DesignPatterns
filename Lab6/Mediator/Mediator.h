//
//  Mediator.h
//  Serve as a hub for messages between HitRatio, Status, Bullet, and Bird.
//  Created by Anne George on 10/21/22.
//

#include "bird.h"
#include "score.h"
#include "bullet.h"
#include <vector>

#ifndef Mediator_h
#define Mediator_h

/******************************
 * For circular dependencies */
class Bird;
class Score;
class HitRatio;
class Bullet;
/*****************************/

class Colleague;
struct Message;

enum status {Bullet_fired, Bird_died};

class Mediator
{
protected:
   std::vector<Colleague*> colleagues;
   
public:
   Mediator() {}
   ~Mediator() {
      for (unsigned int i = 0; i < colleagues.size(); i++)
      {
         delete colleagues[i];
      }
      colleagues.clear();
   }
   
   //get
   Mediator* getMediator() {return this;}
   
   void notify(const Message& message);
   void enroll(Colleague* const enrolle);
   void unenroll(Colleague* const enrolle);
};

struct Message
{
   int type;
   int value;
};

class Colleague
{
protected:
   std::vector<Mediator*> mediators;
   Mediator mediator;
   
public:
   //get
   virtual Colleague* getColleague() = 0;
   
   virtual void notify(Message const &message) = 0;
   void enroll(Mediator* const enrolle);
   void unenroll(Mediator* const enrolle);
};

class BirdColleague : public Colleague
{
private:
   Message message;
   Bird* pBird;
   
public:
   BirdColleague() {}
   BirdColleague(Bird* const bird) : pBird(bird)
   {
      mediator.enroll(this);
   }
   
   //get
   Colleague* getColleague()           { return this; }
   //set
   void setColleague(Bird* bird)
   {
      this->pBird = bird;
      mediator.enroll(this);
   }
   
   void notify(Message const &message) {}
   void wentOutOfBounds();
   void wasShot();
};

class BulletColleague : public Colleague
{
private:
   Message message;
   Bullet* pBullet;
   
public:
   BulletColleague() {}
   /*
   BulletColleague(Bullet* const bullet) : pBullet(bullet)
   {
      mediator.enroll(this);
   }
   */
   
   //get
   Colleague* getColleague()           { return this; }
   //set
   void setColleague(Bullet* bullet)
   {
      this->pBullet = bullet;
      mediator.enroll(this);
   }
   
   void notify(Message const &message) {}
   void firedBullet();
};

class ScoreColleague : public Colleague
{
private:
   Score status;
   
public:
   //get
   Colleague* getColleague() { return this; }
   
   void notify(Message const &message)
   {
      status.adjust(message.value);
   }
};

class HitRatioColleague : public Colleague
{
private:
   HitRatio status;
   
public:
   //get
   Colleague* getColleague() { return this; }
   
   void notify(Message const &message)
   {
      if (message.type == Bird_died) {
         status.adjust(message.value);
      }
   }
};

#endif /* Mediator_h */

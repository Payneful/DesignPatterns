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
class Status;
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
      for (Colleague* objects : colleagues)
      {
         delete objects;
      }
      colleagues.clear();
   }
   
   //get
   Mediator* getMediator() { return this; }
   
   void notify(const Message& message);
   void enroll(Colleague* const enrolle);
   void unenroll(Colleague* const enrolle);
};

struct Message
{
   int type;
   int value;
};

//https://stackoverflow.com/questions/1175646/c-when-should-i-use-a-pointer-member-in-a-class
class Colleague
{
protected:
   Mediator mediator;
   
public:
   //interfaces
   virtual Colleague* getColleague() = 0;
   virtual void notify(Message const &message) = 0;
   
   void enroll(Mediator* const enrolle)   { this->mediator = *enrolle; }
   void unenroll(Mediator* const enrolle) { this->mediator.~Mediator(); }
};

class BirdColleague : public Colleague
{
private:
   Message message;
   Bird* pBird;
   
public:
   BirdColleague()               { mediator.enroll(this); }
   //get
   Colleague* getColleague()     { return this; }
   //set
   void setColleague(Bird* bird) { this->pBird = bird; }
   
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
   BulletColleague()                 { mediator.enroll(this); }
   //get
   Colleague* getColleague()         { return this; }
   //set
   void setColleague(Bullet* bullet) { this->pBullet = bullet; }
   
   void notify(Message const &message) {}
   void firedBullet();
};

class ScoreColleague : public Colleague
{
private:
   Score* pStatus;
   
public:
   ScoreColleague();
   //get
   Colleague* getColleague()        { return this; }
   void setColleague(Score* status) { this->pStatus = status; }
   void notify(Message const &message);
};

class HitRatioColleague : public Colleague
{
private:
   HitRatio* pStatus;
   
public:
   HitRatioColleague();
   //get
   Colleague* getColleague()           { return this; }
   void setColleague(HitRatio* status) { this->pStatus = status; }
   void notify(Message const &message);
};

#endif /* Mediator_h */

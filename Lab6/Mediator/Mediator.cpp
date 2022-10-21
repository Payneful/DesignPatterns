//
//  Mediator.cpp
//  Lab06
//
//  Created by Anne George on 10/21/22.
//

#include <stdio.h>
#include "Mediator.h"

/***************************************************************/
/***************************************************************/
/*                         Mediator                            */
/***************************************************************/
/***************************************************************/

/******************************************************************
 * NOTIFY
 * send message to all enrolled colleagues.
 ****************************************************************/
void Mediator::notify(const Message &message)
{
   for (int i = 0; i < colleagues.size(); i++) {
      colleagues.at(i)->notify(message);
   }
}

/******************************************************************
 * ENROLL
 * add colleagues
 * https://stackoverflow.com/questions/5503352/const-before-or-const-after
 ****************************************************************/
void Mediator::enroll(Colleague* const enrolle)
{
   colleagues.push_back(enrolle);
}

/******************************************************************
 * UNENROLL
 * remove colleagues
 ****************************************************************/
void Mediator::unenroll(Colleague* const enrolle)
{
   for (auto it = colleagues.begin(); it != colleagues.end();) {
      if ((*it)->getColleague() == enrolle)
         colleagues.erase(it);
      else
         ++it;
   }
}

/***************************************************************/
/***************************************************************/
/*                         Colleague                           */
/***************************************************************/
/***************************************************************/

/******************************************************************
 * ENROLL
 * add mediators
 * https://stackoverflow.com/questions/5503352/const-before-or-const-after
 ****************************************************************/
void Colleague::enroll(Mediator* const enrolle)
{
   mediators.push_back(enrolle);
}

/******************************************************************
 * UNENROLL
 * remove mediators
 ****************************************************************/
void Colleague::unenroll(Mediator* const enrolle)
{
   for (auto it = mediators.begin(); it != mediators.end();) {
      if ((*it)->getMediator() == enrolle)
         mediators.erase(it);
      else
         ++it;
   }
}

/***************************************************************/
/***************************************************************/
/*                       BirdColleague                         */
/***************************************************************/
/***************************************************************/

/******************************************************************
 * WENTOUTOFBOUNDS
 * sends message to mediator
 ****************************************************************/
void BirdColleague::wentOutOfBounds()
{
   message.type = Bird_died;
   message.value = -pBird->getPoints();
   mediator.notify(message);
   mediator.unenroll(this);
}

/******************************************************************
 * WASSHOT
 * sends message to mediator
 ****************************************************************/
void BirdColleague::wasShot()
{
   message.type = Bird_died;
   message.value = pBird->getPoints();
   mediator.notify(message);
   mediator.unenroll(this);
}

/***************************************************************/
/***************************************************************/
/*                      BulletColleague                        */
/***************************************************************/
/***************************************************************/

/******************************************************************
 * FIREDBULLET
 * sends message to mediator
 ****************************************************************/
void BulletColleague::firedBullet()
{
   message.type = Bullet_fired;
   message.value = pBullet->getValue();
   mediator.notify(message);
   mediator.unenroll(this);
}

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
   mediator->notify(message);
}

/******************************************************************
 * WASSHOT
 * sends message to mediator
 ****************************************************************/
void BirdColleague::wasShot()
{
   message.type = Bird_died;
   message.value = pBird->getPoints();
   mediator->notify(message);
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
   message.value = -pBullet->getValue();
   mediator->notify(message);
}

/******************************************************************
 * BULLETHITTARGET
 * sends message to mediator
 ****************************************************************/
void BulletColleague::bulletHitTarget()
{
   message.type = Bullet_fired;
   message.value = pBullet->getValue();
   mediator->notify(message);
}

/***************************************************************/
/***************************************************************/
/*                       ScoreColleague                        */
/***************************************************************/
/***************************************************************/
/******************************************************************
 * CONSTRUCTOR
 *https://stackoverflow.com/questions/19962812/error-member-access-into-incomplete-type-forward-declaration-of
 *https://mrcodehunter.com/incomplete-type-is-not-allowed/
 ****************************************************************/
ScoreColleague::ScoreColleague()
{
   pScore = new Score();
}

/******************************************************************
 * NOTIFY
 * sends message to object
 ****************************************************************/
void ScoreColleague::notify(const Message &message)
{
   pScore->adjust(message.value);
}

/***************************************************************/
/***************************************************************/
/*                     HitRatioColleague                       */
/***************************************************************/
/***************************************************************/
/******************************************************************
 * CONSTRUCTOR
 ****************************************************************/
HitRatioColleague::HitRatioColleague()
{
   pHitRatio = new HitRatio();
}

/******************************************************************
 * NOTIFY
 * sends message to object
 ****************************************************************/
void HitRatioColleague::notify(const Message &message)
{
   if (message.type == Bird_died) {
      pHitRatio->adjust(message.value);
   }
}

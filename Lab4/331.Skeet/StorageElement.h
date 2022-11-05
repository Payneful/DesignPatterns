//
//  StorageElement.h
//  Lab08
//
//  Created by Anne George on 11/3/22.
//

#ifndef StorageElement_h
#define StorageElement_h

#include <stdio.h>
#include "point.h"
#include "InterfaceElement.h"
#include "LogicElement.h"

class LogicElement;
class InterfaceElement;

class StorageElement
{
protected:
   Point pt;
   Velocity v;
   double radius;
   int points;
   bool dead;
   LogicElement* pLogic;
   InterfaceElement* pInterface;
};

class StorageBird : public StorageElement
{
   
};

class StorageBullet : public StorageElement
{
   
};

class StorageEffects : public StorageElement
{
   
};

#endif /* StorageElement_h */

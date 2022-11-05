//
//  LogicElement.h
//  Lab08
//
//  Created by Anne George on 11/3/22.
//

#ifndef LogicElement_h
#define LogicElement_h

#include <stdio.h>
#include "StorageElement.h"

class StorageElement;

class LogicElement
{
public:
   virtual void advance(StorageElement se)=0;
   virtual void turn(StorageElement se)=0;
};

class LogicPellet : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicMissile : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicBomb : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicShrapnel : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicFragment : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicExaust : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicStreek : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicStandard : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicSinker : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicFloater : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

class LogicCrazy : public LogicElement
{
   void advance(StorageElement se);
   void turn(StorageElement se);
};

#endif /* LogicElement_h */

//
//  Logic.h
//  Lab03
//
//  Created by Anne George on 11/3/22.
//

#ifndef Logic_h
#define Logic_h

#include <stdio.h>
#include "Storage.h"

class Logic
{
private:
   Storage storage;
   
public:
   Logic();
   void advance();
   void spawn();
   void input();
   class iterator;
   iterator begin();
   iterator end();
   int getFrameLeft();
   int getLevelNumber();
   double getGunAngle();
   bool isPlaying();
   bool isGameOver();
   double getPercentLeft();
};

#endif /* Logic_h */

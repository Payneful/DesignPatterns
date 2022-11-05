//
//  Interface.h
//  Lab08
//
//  Created by Anne George on 11/3/22.
//

#ifndef Interface_h
#define Interface_h

#include "Logic.h"
#include "uiInteract.h"

class Interface
{
private:
   Logic logic;
   
public:
   Interface();
   void input(UserInput ui);
   void processing();
   void output();
};

#endif /* Interface_h */

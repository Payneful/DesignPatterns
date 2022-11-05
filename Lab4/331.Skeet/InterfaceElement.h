//
//  InterfaceElement.h
//  Lab08
//
//  Created by Anne George on 11/3/22.
//

#ifndef InterfaceElement_h
#define InterfaceElement_h

#include <stdio.h>
#include "StorageElement.h"

class InterfaceElement
{
public:
   virtual void draw(StorageElement se)=0;
};

class InterfacePellet : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceMissile : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceBomb : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceShrapnel : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceFragment : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceExaust : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceStreek : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceStandard : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceSinker : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceFloater : public InterfaceElement
{
   void draw(StorageElement se);
};

class InterfaceCrazy : public InterfaceElement
{
   void draw(StorageElement se);
};

#endif /* InterfaceElement_h */

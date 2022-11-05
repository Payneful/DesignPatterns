//
//  Storage.h
//  Lab08
//
//  Created by Anne George on 11/3/22.
//

#ifndef Storage_h
#define Storage_h

#include <stdio.h>
#include "StorageElement.h"
#include "StorageGun.h"
#include "StorageTime.h"

template < class T >
class Storage
{
private:
   StorageElement elements;
   StorageGun gun;
   StorageTime time;
   int numBirds;
   int points;
   int numKilled;
   
public:
   Storage();
   int getPoints();
   int getNumKilled();
   int getNumMissed();
   class iterator;
   iterator begin();
   iterator end();
   class iteratorBird;
   iteratorBird beginBird();
   iteratorBird endBird();
   class iteratorBullet;
   iteratorBullet beginBullet();
   iteratorBullet endBullet();
   void add(StorageElement elements);
   void reset();
};

template < class T >
class Storage<T> :: iterator
{
private:
   T *p;
   
public:
   iterator() : p(NULL) {}
   iterator(T *p) : p(p) {}
   iterator(const iterator &rhs) : p(rhs.p) {}
   ~iterator() {p = NULL;}
   
   iterator & operator = (T *p) {this->p = p;}
   inline bool operator == (const iterator &rhs) const {return this->p == rhs.p;}
   inline bool operator != (const iterator &rhs) const {return this->p != rhs.p;}
   
   iterator & operator ++ () {p++; return *this;}
   iterator operator ++ (int postfix) {iterator it(*this); p++; return it;}
   iterator & operator -- () {p--; return *this;}
   iterator operator -- (int postfix) {iterator it(*this); p--; return it;}
   
   T & operator * () {return *p;}
};

#endif /* Storage_h */

/***********************************************************************
 * Header File:
 *    SKEET
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The game class
 ************************************************************************/

#pragma once

#include "point.h"
#include "uiInteract.h"
#include "bird.h"
#include "bullet.h"
#include "effect.h"
#include "gun.h"
#include "time.h"
#include "score.h"

#include <list>

/*************************************************************************
 * Skeet
 * The game class
 *************************************************************************/
class Skeet
{
public:
    Skeet(Point & dimensions) : dimensions(dimensions),
        gun(Point(800.0, 0.0)), time(), score(), hitRatio() {}

    // handle all user input
    void interact(const UserInput& ui);

    // move the gameplay by one unit of time
    void animate();

    // output everything on the screen
    void drawLevel()  const;    // output the game
    void drawStatus() const;    // output the status information

    // is the game currently playing right now?
    bool isPlaying() const { return time.isPlaying();  }

    // Execute
    template <typename T> void execute(void *callback, T context);

    // Orders
    void *drawEffect(Effect* subject);
    void *drawBird(Bird* subject);
    void *drawBullet(Bullet* subject);
    void *drawGun(Gun subject);

    void *advanceEffect(Effect* subject);
    void *advanceBird(Bird* subject);
    void *advanceBullet(Bullet* subject);

    void *killBird(Bird* subject);
    void *killBullet(Bullet* subject);
    /*
    // Function Pointers
    void (*drawEffect)(Effect);
    void (*drawBird)(Bird);
    void (*drawBullet)(Bullet);
    void (*drawGun)(Gun);

    void (*advanceBird)(Bird);
    void (*advanceEffect)(Effect);
    void (*advanceBullet)(Bullet);

    void (*killBird)(Bird);
    void (*killBullet)(Bullet);
    */

private:
    // generate new birds
    void spawn();                  
    void drawBackground(double redBack, double greenBack, double blueBack) const;
    void drawTimer(double percent,
                   double redFore, double greenFore, double blueFore,
                   double redBack, double greenBack, double blueBack) const;
    
    Gun gun;                       // the gun
    std::list<Bird*> birds;        // all the shootable birds
    std::list<Bullet*> bullets;    // the bullets
    std::list<Effect*> effects;    // the fragments of a dead bird.
    Time time;                     // how many frames have transpired since the beginning
    Score score;                   // the player's score
    HitRatio hitRatio;               // the hit ratio for the birds
    Point dimensions;              // size of the screen
};

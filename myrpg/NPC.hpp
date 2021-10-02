#ifndef NPC_hpp
#define NPC_hpp

#include <stdio.h>
#include "Stats.hpp"

class NPC {

private:


public:
    Stats stats;
    Stats getStats(); // get stats
    void setStats(const Stats& s); // set stats

    // These methods must be declared with the keyword "virtual" so that
    // they will be called correctly if overridden from other sub-classes (e.g. Wizard)
    // We will see this aspect of OOP and the use of virtual methods after reading week
    // For the moment you simply need to add this keyword when you declare/implement these methods

    virtual void print(); // print stats
    virtual void defend(int attackStrength);
    virtual int  attack();

    bool isAlive();  // returns true if the creature is alive

    NPC();  // default constructor

};

#endif /* NPC_hpp */

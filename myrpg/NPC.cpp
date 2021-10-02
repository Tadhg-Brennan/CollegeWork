#include "NPC.hpp"
#include "Stats.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

NPC::NPC():stats(Stats((rand()%20)+1, (rand()%5)+1, true))
{
   cout << "Successful NPC construction completed.";
}

void NPC::print()
{
    stats.print();
}

int NPC::attack()
{
    int roll = (rand()%6)+1;
    int atk = roll*stats.getskill();
    return atk;
}

void NPC::defend(int atk)
{
    int roll = (rand()%6)+1;
    int defense = roll*stats.getskill();
    int damage = defense - atk;

    if(damage < 0){
        int newstrength = stats.getstrength() - damage;
        if(newstrength < 0){
            stats.setstrength(0);
            stats.killed();
            cout << "RIP this NPC." << endl;
        } else {
            stats.setstrength(newstrength);
            cout << "This NPC has sustained damage but has walked it off." << endl;
        }
    }
}

bool NPC::isAlive()
{
    if(stats.isalive()){
        return true;
    } else {
        return false;
    }
}

void NPC::setStats(const Stats& s)
{
    stats = s;
}

Stats NPC::getStats()
{
    return stats;
}

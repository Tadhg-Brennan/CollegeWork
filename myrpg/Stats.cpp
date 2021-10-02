#include "Stats.hpp"
#include <iostream>
#include <stdlib.h>


using namespace std;


int Stats::getstrength()
{
    return strength;
}

int Stats::getskill()
{
    return skill;
}

bool Stats::isalive()
{
    return alive;
}


Stats::Stats(int st, int sk, bool a)
{
	strength = st;
	skill = sk;
	alive = a;
}



void Stats::print()
{
	cout << "Strength: " << strength << endl;
	cout << "Skill: " << skill <<  endl;
	cout << "Alive: ";

	if (alive == true){
        cout << "Thankfully, yes" << endl;
    } else {
        cout << "Alas, no"<<endl;
    }
}


void Stats::setstrength(int i)
{
    strength = i;
}


void Stats::killed()
{
    alive = false;
}


void Stats::setalive()
{
    alive= true;
}

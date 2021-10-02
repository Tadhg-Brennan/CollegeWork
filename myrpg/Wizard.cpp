#include "Wizard.hpp"
#include "NPC.hpp"
#include "Stats.hpp"
#include <iostream>

using namespace std;

Wizard::Wizard():NPC()
{
    cout << "The wizard, he approaches." << endl;
}

void Wizard::defend(int at)
{
    NPC::defend(at);
    if(!stats.isalive()){

        stats.setstrength(1);
        stats.setalive();
        cout << "Wizards are immortal fool." << endl;
    }
}

void Wizard::print()
{
    stats.print();
}

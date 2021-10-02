#ifndef Wizard_hpp
#define Wizard_hpp
#include "NPC.hpp"

#include <stdio.h>

class Wizard : public NPC
{
public:
    Wizard();
    virtual void print();
    virtual void defend(int at);
};


#endif /* Wizard_hpp */

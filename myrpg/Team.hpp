#ifndef Team_hpp
#define Team_hpp

#include <stdio.h>
#include "NPC.hpp"

// Define a structure to use it to hold the linked list
struct Node {
	NPC*  npc; // pointer to
    Node* next;//pointer to the next node.
};
class Team
{
/**
 * Represents a team of NPCs
 * Uses a LinkedList to store pointers to NPCs
 */
protected:
    // Pointers used to implement the linked list


public:
    void add(NPC* npc); // add one NPC to the list
    NPC* at(int i); // returns the #i NPC
    int numAlive(); // returns number of alive NPCs
    int getSize();   // returns the number of NPCs in this team
	struct Node {
		NPC*  npc; // pointer to
		Node* next;//pointer to the next node.
	};
	Node* head;
    Node* tail;
    // destructor
    // this method is not mandatory for this lab.
    // however, if you want to implement it, visit the linked list and delete all items (see method destroy
    // in previous lab
    Team();
};

#endif /* Team_hpp */

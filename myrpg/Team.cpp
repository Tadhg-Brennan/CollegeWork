#include "Team.hpp"
#include "NPC.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Team::Team()
{
	Node* head = NULL;
    Node* tail = NULL;
	cout << "Team successfully constructed" << endl;
}

void Team::add(NPC* thisNPC)
{
    Node* newNPC = new Node;
    newNPC -> npc = thisNPC;
    newNPC -> next = NULL;

    if(head == NULL){
        head = tail = newNPC;
 	} else {
 		tail -> next = newNPC;
 		tail = newNPC;
 	}
}


int Team::numAlive()
{
    int n = 0;
    Node* curr = head;
    for (int i =0; i<getSize(); i++){
        if (curr -> npc -> isAlive()){
            n++;
        }

        curr = curr->next;
    }

    return n;
}

NPC* Team::at(int i)
{
    Node* curr = head;
    for(int j = 1; j < i; j++){
        curr = curr->next;
    }

    return curr -> npc;
}

int Team::getSize()
{
    int n;
    Node* curr;
    curr = head;

    if(head== NULL){
        n = 0;
    } else {
        n = 1;
    }
    while(curr->next != NULL){
        n++;
        curr = curr->next;
    }
    return n;
}

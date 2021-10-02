#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "NPC.hpp"
#include "Team.hpp"
#include "Wizard.hpp"
#include <ctime>

using namespace::std;

int main(){

    srand (time(0));

    cout << "Please enter the number of NPCs per team:" << endl;
    int num;
    cin >> num;
    cout << "Please enter the number of rounds:" << endl;
    int round;
    cin >> round;

    Team homeTeam;
    Team awayTeam;

    // extract the random position of the two wizards
    int indexWizard1 = rand()%num;
    int indexWizard2 = rand()%num;
    for(int i=0; i<num; i++)
    {
    	homeTeam.add(i == indexWizard1 ? new Wizard() : new NPC());
    	awayTeam.add(i == indexWizard2 ? new Wizard() : new NPC());
    }
    for(int i = 0; i < num ; i++){

        if(i == indexWizard1){
            NPC* Wizard1 = new Wizard;
            homeTeam.add(Wizard1);
        } else {
            NPC* newNPC = new NPC;
            homeTeam.add(newNPC);
        }

        if(i==indexWizard2)
        {
            NPC* Wizard2 = new Wizard;
            awayTeam.add(Wizard2);
        } else {
            NPC* newNPC2 = new NPC;
            awayTeam.add(newNPC2);
        }
    }
    cout << endl << endl << endl;

    for(int i = 0; i <= round; i++){

        cout << "Round: " << i+1 << endl;

        for(int j = 0; j <= num; j++){

            cout<<"Home Team's Turn "<< j << endl;

            if(homeTeam.at(j) -> isAlive()){
                if(awayTeam.at(j) -> isAlive()){
                    awayTeam.at(j) -> defend(homeTeam.at(j) -> attack());
                    awayTeam.at(j) -> print();
                    cout << endl << endl;
                } else {
                    cout << "player "<< j << " of the away team is dead."<<endl;
                }

            } else {
                if(awayTeam.at(j) -> isAlive()){
                        cout << "player " << j << " of the home team is dead." << endl;
                } else {
                        cout<< "Both players have died in an odd stalemate."<< endl;
                }

            }
        }

        for(int j = 0; j <= num; j++){

            cout<<"Away Team's Turn "<< j << endl;

            if(awayTeam.at(j) -> isAlive()){
                if(homeTeam.at(j) -> isAlive()){
                    homeTeam.at(j) -> defend(awayTeam.at(j) -> attack());
                    homeTeam.at(j) -> print();
                    cout << endl << endl;
                } else {
                    cout << "player "<< j << " of the home team is dead."<<endl;
                }

            } else {
                if(homeTeam.at(j) -> isAlive()){
                        cout << "player " << j << " of the home team is dead." << endl;
                } else {
                        cout<< "Both players have died in an odd stalemate."<< endl;
                }

            }
        }

    }
    if(homeTeam.numAlive() > awayTeam.numAlive()){
        cout<< "Home Team are victorious."<< endl;
    } else if(homeTeam.numAlive() < awayTeam.numAlive()){
        cout << "Away Team are victorious." << endl;
    } else {
        cout << "The battle ended in a draw."<< endl;
    }
	int end;
	cin >> end;
    return 0;
}

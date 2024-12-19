#ifndef COMBAT_H
#define COMBAT_H

#include <iostream>
#include <random>
#include <queue>
#include <vector>
#include <unordered_map>
#include "character.h"
#include "numberGen.h"

class combat{
    private:
        std::priority_queue<character> turnQueue; //Denotes turn queue for combat
        std::unordered_map<std::string, character> combatants; //Stores all live combatants
        int playerTeam; //Holds members of player team
        int enemyTeam; //Holds members of enemy team
        bool ongoing; //Denotes ongoing combat, if false, end of combat and exits combat loop

    public:
        
        //Constructor for inputting combatants into instance
        combat(std::unordered_map<std::string, character>);

        //Queue Functions
        void outputQueue(); //Outputs the current turn queue 
        
        //Combat Loop Function
        void combatLoop();
        void updateCombat(); //Updates order of turn queue after combat phases
        void outputHealthStates();
        character attack(character);
        //void guard(character);
};

#endif
#include "combat.h"

combat::combat(std::unordered_map<std::string, character> combatants){
    //Inputs combatants to class vector for interal storage
    this->combatants = combatants;

    //Initializing variables
    ongoing = true;
    playerTeam = 0;
    enemyTeam = 0;

    //Places combatants on teams, when adding revive skills probably move this back into update combat within the if statement to update newly revived
    for(auto c : combatants){
        if(c.second.getControl())
            playerTeam++;
        else    
            enemyTeam++;
    }
}

//Updates the combat state, including outputting health and updating turn queue
void combat::updateCombat(){
    for(auto c : combatants){
        //Checks if combatant is defeated
        if(c.second.getHealth() > 0){
            //Pushes combatants accordingly based on speed to queue
            turnQueue.push(c.second);
        }   
    }
}

//Output health states of all combatants
void combat::outputHealthStates(){
    for(auto c : combatants){
        //Checks if combatant is defeated
        if(c.second.getHealth() > 0){
            std::cout << c.second.getName() << " | Health: " << c.second.getHealth() << std::endl;
        }   
    }
    std::cout << std::endl;
}

//Outputs the turn queue
void combat::outputQueue(){
    //Temporary variable used to output the character objects
    character temp;
    
    std::cout << "Turn Queue:" << std::endl;
    
    //Outputs the turn queue, empties the queue in the process unfortunately
    while(!turnQueue.empty()){
        temp = turnQueue.top();
        std::cout << temp.getName() << std::endl;
        turnQueue.pop();
    }

    //Repopulates the queue
    updateCombat();
}

//Function for the combat loop
void combat::combatLoop(){
    //Stores character with turn currently
    character currentCharacter;
    //Stores target
    character target;
    //Tracks current turn
    int turn = 1;
    
    std::cout << "Combat Engaged!" << std::endl;

    //Gameplay loop
    while(ongoing){
        updateCombat(); //Updates the turn queue

        //Barriers to help visualize actions in current turn
        std::cout << "======================================================================" << std::endl;
        std::cout << "Turn: " << turn << std::endl;
        
        while(!turnQueue.empty() && ongoing){
            outputHealthStates();
            currentCharacter = turnQueue.top(); //Sets top of queue to currentCharacter
            turnQueue.pop(); //Sets next turn to next character

            //Current character attacks target
            target = attack(currentCharacter);

            //If target is defeated, elimination message plays
            if(target.getHealth() <= 0){
                std::cout << target.getName() << " has been defeated!\n" << std::endl;
                if(target.getControl())
                    playerTeam--;
                else    
                    enemyTeam--;
            }

            //Victory for the player team
            if(enemyTeam < 1){
                ongoing = false;
                std::cout << "Victory!\n";
            }

            //Defeat for the player team
            if(playerTeam < 1){
                ongoing = false;
                std::cout << "Defeat...\n";
            }
        }
        //Barriers to help visualize actions in current turn
        std::cout << "======================================================================" << std::endl;
    }
}

//Function determining attack
character combat::attack(character currentCharacter){
    std::unordered_map<int, std::string> targets;
    int damage;
    int count = 1; //Used to store order number for target options
    int choice; //Used to store user input

    //If player, prompt to choose target
    if(currentCharacter.getControl()){
        //Inputs valid targets into targets hash map for selection and outputs them to the user
        for(auto c : combatants){
            //Doesn't output if entry is itself or is a defeated opponent
            if(c.second != currentCharacter && c.second.getHealth() > 0){
                std::cout << count << ". " << c.first << std::endl;
                targets.emplace(count, c.first);
            }
        }

        //Prompts user to select target
        do{
            std::cout << "Choose Target: ";
            std::cin >> choice;
            if(choice < 1 || choice > count)
                std::cout << "Invalid choice, please select valid target." << std::endl;
        }while (choice < 1 || choice > count); //If invalid target, outputs error message and reprompts
        std::cout << std::endl;
    }
    //If AI, randomly chooses target
    else{
        //Inputs valid targets into targets hash map for selection, only player and player controlled characters are valid targets
        for(auto c : combatants){
            //Not valid entry if is itself, a defeated opponent, or not player character
            if(c.second != currentCharacter && c.second.getHealth() > 0 && c.second.getControl() != currentCharacter.getControl()){
                targets.emplace(count, c.first);
            }

            //Generates random target for AI
            choice = randomNumber(1, count);
        }
    }
    //Grabs target name from targets hash map and obtains character from combatants hash map storing it in target
    character& target = combatants[targets[choice]];

    //Subtracts the attack of current character with target's health to deal damage
    damage = (currentCharacter.getAttack() - target.getDefense());
    target.setHealth(target.getHealth() - damage);

    //Outputs damage message
    std::cout << currentCharacter.getName() << " strikes " << target.getName() << " for " << damage << "!\n" << std::endl;

    return target;
}
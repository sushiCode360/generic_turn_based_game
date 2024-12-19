#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "numberGen.h"

//Class containing all attributes of character
class character{
    private:
        std::string name;
        int level;
        int experience;
        int health;
        int attack;
        int defense; 
        int speed;
        bool control; //If true, player controlled, if false, AI controlled

    public:
        //Constructors
        character();
        
        //Set functions
        void setName(std::string);
        void setLevel(int);
        void setExp(int);
        void setHealth(int);
        void setAttack(int);
        void setDefense(int);
        void setSpeed(int);
        void setControl(bool);

        //Get functions
        std::string getName();
        int getLevel();
        int getExp();
        int getHealth();
        int getAttack();
        int getDefense();
        int getSpeed();
        bool getControl();

        //Output functions
        void outputName(); //Outputs name
        void outputLevel(); //Outputs level
        void outputExp(); //Outputs current exp
        void outputHealth(); //Outputs health
        void outputAttack(); //Outputs attack
        void outputDefense(); //Outputs defense
        void outputSpeed(); //Outputs speed
        void outputControl(); //Outputs if character is AI or character controlled
        void outputCharacter(); //Outputs all aspects of character

        //Operator overload< for priority queue involving character speed
        bool operator< (const character& other) const;

        //Operator overload== for comparing character names
        bool operator== (const character& other) const;

        //Operator overload!= for comparing character names
        bool operator!= (const character& other) const;
};

#endif
#include "character.h"

//Constructor for character class
character::character(){
    name = "Default"; //Passes parameter name to character name
    level = 0; //Sets level
    experience = 0; //Sets experience
    health = 10; //Sets health, default is 10
    attack = 2; //Sets attack, default is 2
    defense = 1;
    speed = 5; //Sets speed, default is 5
    control = false; //Sets character control, default is false
};

//SET FUNCTIONS

//Sets name of character
void character::setName(std::string name){
    this->name = name;
}

//Sets level of character
void character::setLevel(int level){
    this->level = level;
}

//Sets experience of character
void character::setExp(int experience){
    this->experience = experience;
}

//Sets health of character
void character::setHealth(int health){
    this->health = health;
}

//Sets attack of character
void character::setAttack(int attack){
    this->attack = attack;
}

//Sets speed of character
void character::setSpeed(int speed){
    this->speed = speed;
}

//Sets control of character
void character::setControl(bool control){
    this->control = control;
}

//GET FUNCTIONS

//Gets name of character
std::string character::getName(){
    return name;
}

//Gets level of character
int character::getLevel(){
    return level;
}

//Gets experience of character
int character::getExp(){
    return experience;
}

//Gets health of character
int character::getHealth(){
    return health;
}

//Gets attack of character
int character::getAttack(){
    return attack;
}

//Gets defense of character
int character::getDefense(){
    return defense;
}

//Gets speed of character
int character::getSpeed(){
    return speed;
}

//Gets control of character
bool character::getControl(){
    return control;
}

//OUTPUT FUNCTIONS

//Outputs name of character
void character::outputName(){
    std::cout << "Name: " << name << std::endl;
}

//Outputs level of character
void character::outputLevel(){
    std::cout << "Level: " << level << std::endl;
}

//Outputs experience of character
void character::outputExp(){
    std::cout << "Experience: " << experience << std::endl;

}
//Outputs health of character
void character::outputHealth(){
    std::cout << "Health: " << health << std::endl;
}

//Outputs attack of character
void character::outputAttack(){
    std::cout << "Attack: " << attack << std::endl;
}

//Outputs speed of character
void character::outputSpeed(){
    std::cout << "Speed: " << speed << std::endl;
}

//Outputs control of character
void character::outputControl(){
    if(control)
        std::cout << "Player Controlled." << std::endl;
    else
        std::cout << "AI Controlled." << std::endl;
}

//Outputs all attributes of character
void character::outputCharacter(){
    outputName();
    outputLevel();
    outputExp();
    outputHealth();
    outputAttack();
    outputSpeed();
    outputControl();
}

//Define operator< for priority queue (reverse for descending order)
bool character::operator< (const character& other) const {
    //If speed is tied, then randomly choose from the two
    if (this->speed == other.speed) {
        int randNum = randomNumber(0, 1);
        return randNum == 0;  // 50/50 chance
    }
    return speed < other.speed; // Higher speed = higher priority
}

//Define operator== for comparing two characters names
bool character::operator== (const character& other) const {
    return name == other.name; //True if same name, false if not
}

//Define operator!= for comparing two characters names
bool character::operator!= (const character& other) const {
    return name != other.name; //False if same name, true if not
}
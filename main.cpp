#include <iostream>
#include <unordered_map>
#include <vector>
#include "character.h"
#include "combat.h"

int main(){
    character player, boblin;
    player.setName("Limpboy");
    boblin.setName("Boblin");
    player.setControl(true);

    std::unordered_map<std::string, character> combatants;
    combatants.emplace(player.getName(), player);
    combatants.emplace(boblin.getName(), boblin); 

    combat encounter(combatants);
    encounter.combatLoop();
}
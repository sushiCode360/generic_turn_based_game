#include "numberGen.h"

int randomNumber(int lower, int upper){
    std::random_device rd;  // Non-deterministic random number generator (used to seed the engine)
    std::ranlux48 gen(rd()); // Mersenne Twister engine seeded with rd
    std::uniform_int_distribution<> dis(lower, upper); //Range from lower to upper
    int randomInt = dis(gen);

    return randomInt;
}
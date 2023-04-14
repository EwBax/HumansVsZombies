//
// Created by ewanb on 2023-04-13.
//

#include "../inc/Organism.h"
#include "../inc/City.h"

// Function to remove Organism from current position and place in new position
void Organism::setPosition(int newX, int newY) {

    // Removing organism from current position
    city->setOrganism(nullptr, x, y);

    // updating x and y
    x = newX;
    y = newY;

    // Placing in new position
    city->setOrganism(this, x, y);

}


// Resets hasMoved after first pass through city
void Organism::resetHasMoved() {
    hasMoved = false;
}


// Randomly picking from directions
Organism::direction Organism::pickDirection(std::vector<direction> directions) {

    //https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
    // Providing seed value
    srand((unsigned) time(nullptr));

    int direction = rand() % directions.size();

    return directions.at(direction);
}



std::ostream &operator<<(std::ostream &output, Organism *organism) {

    // Getting proper color
    switch (organism->orgType) {

        case HUMAN_CH:
            output << "\033[48;5;" + std::to_string(HUMAN_COLOR) + "m";
            break;

        case ZOMBIE_CH:
            output << "\033[48;5;" + std::to_string(ZOMBIE_COLOR) + "m";
            break;

    }

    output << " " << organism->orgType << " ";

    // resetting color
    output << "\033[48;5;" + std::to_string(DEFAULT_COLOR) + "m";

    return output;
}

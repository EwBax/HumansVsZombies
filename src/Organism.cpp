//
// Created by ewanb on 2023-04-13.
//

#include "../inc/Organism.h"
#include "../inc/City.h"

// Function to remove Organism from current position and place in new position
void Organism::setPosition(int newX, int newY) {

    // Removing from current position
    city->setOrganism(nullptr, x, y);

    // updating x and y
    x = newX;
    y = newY;

    // Placing in new position
    city->setOrganism(this, x, y);

}

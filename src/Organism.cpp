//
// Created by ewanb on 2023-04-13.
//

#include "../inc/Organism.h"

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

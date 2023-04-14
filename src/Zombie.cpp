//
// Created by ewanb on 2023-04-13.
//

#include "../inc/Zombie.h"
#include "../inc/Human.h"
#include "../inc/City.h"

// Function to handle the zombie's turn
void Zombie::turn() {

    if (!hasMoved) {
        move();
        hasMoved = true;
        breedCounter++;

        if (breedCounter >= ZOMBIE_BREED) {
            // If breeding successful, reset counter
            if (breed()) {
                breedCounter = 0;
            }
        }

        if (starveCounter >= ZOMBIE_STARVE) {
            starve();
        }
    }

}


// Function to either move and eat
void Zombie::move() {

    std::vector<direction> directions = findHumanDirections();

    // If there are no human directions (no adjacent humans), then instead find open directions
    // And increment starveCounter
    if (directions.empty()) {
        directions = findOpenDirections();
        starveCounter++;

        // If there are no open directions, return early.
        if (directions.empty()) {
            return;
        }

    } else {
        // Resetting starve counter because if findHumanDirections is not empty then the zombie
        // will eat this turn
        starveCounter = 0;
    }

    direction chosenDirection = pickDirection(directions);

    // Setting the Zombie's new position
    switch (chosenDirection) {

        case WEST:
            setPosition(x - 1, y);
            break;

        case NORTH_WEST:
            setPosition(x - 1, y - 1);
            break;

        case NORTH:
            setPosition(x, y - 1);
            break;

        case NORTH_EAST:
            setPosition(x + 1, y - 1);
            break;

        case EAST:
            setPosition(x + 1, y);
            break;

        case SOUTH_EAST:
            setPosition(x + 1, y + 1);
            break;

        case SOUTH:
            setPosition(x, y + 1);
            break;

        case SOUTH_WEST:
            setPosition(x - 1, y + 1);
            break;

    } // end switch

} // end function move


// Function to find adjacent Human directions
std::vector<Organism::direction> Zombie::findHumanDirections() {

    std::vector<Zombie::direction> humanDirections;

    // Checking each direction, making sure Zombie is not on edge in that direction
    // Also checking if there is an organism there, and if it is a human
    // west is x-1, east is x+1
    // north is y-1, south is y+1

    // WEST
    if (x > 0 && city->getOrganism(x - 1, y) != nullptr
              && city->getOrganism(x - 1, y)->getOrgType() == HUMAN_CH) {
        humanDirections.push_back(WEST);
    }
    //NORTH WEST
    if (x > 0 && y > 0
              && city->getOrganism(x - 1, y - 1) != nullptr
              && city->getOrganism(x - 1, y - 1)->getOrgType() == HUMAN_CH) {
        humanDirections.push_back(NORTH_WEST);
    }
    // NORTH
    if (y > 0 && city->getOrganism(x, y - 1) != nullptr
              && city->getOrganism(x, y-1)->getOrgType() == HUMAN_CH) {
        humanDirections.push_back(NORTH);
    }
    //NORTH EAST
    if (x < GRID_WIDTH - 1 && y > 0
            && city->getOrganism(x + 1, y - 1) != nullptr
            && city->getOrganism(x + 1, y - 1)->getOrgType() == HUMAN_CH) {
        humanDirections.push_back(NORTH_EAST);
    }
    // EAST
    if (x < GRID_WIDTH - 1
            && city->getOrganism(x + 1, y) != nullptr
            && city->getOrganism(x + 1, y)->getOrgType() == HUMAN_CH) {
        humanDirections.push_back(EAST);
    }
    //SOUTH EAST
    if (x < GRID_WIDTH - 1 && y < GRID_HEIGHT - 1
            && city->getOrganism(x + 1, y + 1) != nullptr
            && city->getOrganism(x + 1, y + 1)->getOrgType() == HUMAN_CH) {
        humanDirections.push_back(SOUTH_EAST);
    }
    // SOUTH
    if (y < GRID_HEIGHT - 1
            && city->getOrganism(x, y + 1) != nullptr
            && city->getOrganism(x, y + 1)->getOrgType() == HUMAN_CH) {
        humanDirections.push_back(SOUTH);
    }
    //SOUTH WEST
    if (x > 0 && y < GRID_HEIGHT - 1
              && city->getOrganism(x - 1, y + 1) != nullptr
              && city->getOrganism(x - 1, y + 1)->getOrgType() == HUMAN_CH) {
        humanDirections.push_back(SOUTH_WEST);
    }

    return humanDirections;

}


// Function to find adjacent open directions
std::vector<Organism::direction> Zombie::findOpenDirections() {

    std::vector<Zombie::direction> openDirections;

    // Checking each direction, making sure Zombie is not on edge in that direction
    // Also checking if there is an organism there
    // west is x-1, east is x+1
    // north is y-1, south is y+1

    // WEST
    if (x > 0 && city->getOrganism(x - 1, y) == nullptr) {
        openDirections.push_back(WEST);
    }
    //NORTH WEST
    if (x > 0 && y > 0 && city->getOrganism(x - 1, y - 1) == nullptr) {
        openDirections.push_back(NORTH_WEST);
    }
    // NORTH
    if (y > 0 && city->getOrganism(x, y - 1) == nullptr) {
        openDirections.push_back(NORTH);
    }
    //NORTH EAST
    if (x < GRID_WIDTH - 1 && y > 0 && city->getOrganism(x + 1, y - 1) == nullptr) {
        openDirections.push_back(NORTH_EAST);
    }
    // EAST
    if (x < GRID_WIDTH - 1 && city->getOrganism(x + 1, y) == nullptr) {
        openDirections.push_back(EAST);
    }
    //SOUTH EAST
    if (x < GRID_WIDTH - 1 && y < GRID_HEIGHT - 1 \
                           && city->getOrganism(x + 1, y + 1) == nullptr) {
        openDirections.push_back(SOUTH_EAST);
    }
    // SOUTH
    if (y < GRID_HEIGHT - 1 && city->getOrganism(x, y + 1) == nullptr) {
        openDirections.push_back(SOUTH);
    }
    //SOUTH WEST
    if (x > 0 && y < GRID_HEIGHT - 1 && city->getOrganism(x - 1, y + 1) == nullptr) {
        openDirections.push_back(SOUTH_WEST);
    }

    return openDirections;
}


// Function to breed/convert adjacent human. Returns true if successful, false if not.
bool Zombie::breed() {

    // Finding adjacent human's
    std::vector<direction> humanDirections = findHumanDirections();

    // Returning false early if there are no adjacent humans
    if (humanDirections.empty()) {
        return false;
    }

    direction chosenDirection = pickDirection(humanDirections);

    // Setting adjacent square in chosen direction to a new Zombie
    switch (chosenDirection) {

        case WEST:
            city->setOrganism(new Zombie(city, x - 1, y), x - 1, y);
            break;

        case NORTH_WEST:
            city->setOrganism(new Zombie(city, x - 1, y - 1), x - 1, y - 1);
            break;

        case NORTH:
            city->setOrganism(new Zombie(city, x, y - 1), x, y - 1);
            break;

        case NORTH_EAST:
            city->setOrganism(new Zombie(city, x + 1, y - 1), x + 1, y - 1);
            break;

        case EAST:
            city->setOrganism(new Zombie(city, x + 1, y), x + 1, y);
            break;

        case SOUTH_EAST:
            city->setOrganism(new Zombie(city, x + 1, y + 1), x + 1, y + 1);
            break;

        case SOUTH:
            city->setOrganism(new Zombie(city, x, y + 1), x, y + 1);
            break;

        case SOUTH_WEST:
            city->setOrganism(new Zombie(city, x - 1, y + 1), x - 1, y + 1);
            break;

    }

    return true;

}


// Function to simply replace zombie with new human
void Zombie::starve() {
    city->setOrganism(new Human(city, x, y), x, y);
}










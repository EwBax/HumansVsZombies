//
// Created by ewanb on 2023-04-13.
//



#include "../inc/Human.h"
#include "../inc/City.h"

// Function to run the Human's turn including movement and recruiting
void Human::turn() {

    if (!hasMoved) {
        move();
        hasMoved = true;
        recruitCounter++;

        // Recruiting and resetting counter
        if (recruitCounter >= HUMAN_RECRUIT) {
            recruit();
            recruitCounter = 0;
        }

    }

}


void Human::move() {

    std::vector<direction> openDirections = findOpenDirections();

    // Only moving if there is at least one open direction
    if (!openDirections.empty()) {

        // Getting the random chosenDirection to move in
        direction chosenDirection = pickDirection(openDirections);

        // Setting the Human's new position
        switch (chosenDirection) {

            case WEST:
                setPosition(x - 1, y);
                break;

            case NORTH:
                setPosition(x, y - 1);
                break;

            case EAST:
                setPosition(x + 1, y);
                break;

            case SOUTH:
                setPosition(x, y + 1);
                break;

        } // end switch
    }

} // end function move


// Finding which directions are open and returning vector containing those directions (as enum)
std::vector<Organism::direction> Human::findOpenDirections() {

    std::vector<Organism::direction> openDirections;

    // Checking each direction, making sure Human is not on edge in that direction, and spot is not
    // occupied
    // west is x-1, east is x+1
    // north is y-1, south is y+1

    // WEST
    if (x > 0 && city->getOrganism(x - 1, y) == nullptr) {
        openDirections.push_back(WEST);
    }
    // NORTH
    if (y > 0 && city->getOrganism(x, y - 1) == nullptr) {
        openDirections.push_back(NORTH);
    }
    // EAST
    if (x < GRID_WIDTH - 1 && city->getOrganism(x + 1, y) == nullptr) {
        openDirections.push_back(EAST);
    }
    // SOUTH
    if (y < GRID_HEIGHT - 1 && city->getOrganism(x, y + 1) == nullptr) {
        openDirections.push_back(SOUTH);
    }

    return openDirections;

}


// Function to recruit a new Human to an adjacent space
void Human::recruit() {

    // Getting open directions
    std::vector<direction> openDirections = findOpenDirections();

    // Only recruiting if there is at least one open direction
    if (!openDirections.empty()) {

        // Getting the random chosenDirection to move in
        direction chosenDirection = pickDirection(openDirections);

        switch (chosenDirection) {

            case WEST:
                // Setting a new human to the coordinates x-1, y
                city->setOrganism(new Human(city, x - 1, y), x - 1, y);
                break;

            case NORTH:
                city->setOrganism(new Human(city, x, y - 1), x, y - 1);
                break;

            case EAST:
                city->setOrganism(new Human(city, x + 1, y), x + 1, y);
                break;

            case SOUTH:
                city->setOrganism(new Human(city, x, y + 1), x, y + 1);
                break;

        }

    }

}// end function Recruit

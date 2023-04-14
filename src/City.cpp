//
// Created by ewanb on 2023-04-13.
//

#include "../inc/City.h"
#include "../inc/Human.h"
#include "../inc/Zombie.h"


City::City() : generation(1) {

    spawnHumans();
    spawnZombies();

}


// Returns a pointer to the organism at coordinates x,y
Organism* City::getOrganism(int x, int y) {
    return grid[y][x];
}

// Sets the organism pointer at coordinates x,y
void City::setOrganism(Organism* organism, int x, int y) {
    grid[y][x] = organism;
}


// Iterates through the whole grid performs each organism's turn, then iterates again and resets
// move flag
void City::move() {

    for (auto & row : grid) {
        for  (auto & organism : row) {
            if (organism != nullptr) {
                organism->turn();
            }
        }
    }

}


// Function to reset move flags
void City::reset() {

    for (auto & row : grid) {
        for  (auto & organism : row) {
            if (organism != nullptr) {
                organism->resetHasMoved();
            }
        }
    }

    generation++;

}


// Function to randomly spawn set number of humans
void City::spawnHumans() {

    for (int i = 0; i < HUMAN_STARTCOUNT; i++) {

        // Finding an empty spot
        std::array<int, 2> coords = findEmptySpot();

        // Spawning the human on the empty spot
        setOrganism(new Human(this, coords[0], coords[1]), coords[0], coords[1]);

    }

}


// Function to randomly spawn set number of zombies
void City::spawnZombies() {

    for (int i = 0; i < ZOMBIE_STARTCOUNT; i++) {

        // Finding an empty spot
        std::array<int, 2> coords = findEmptySpot();

        // Spawning the zombie on the empty spot
        setOrganism(new Zombie(this, coords[0], coords[1]), coords[0], coords[1]);

    }

}


// Function to find a random empty spot on the grid
std::array<int, 2> City::findEmptySpot() {

    // Providing seed value
    srand((unsigned) time(nullptr));

    // Randomly generating coordinates
    int x = rand() % GRIDSIZE;
    int y = rand() % GRIDSIZE;

    // Looping until randomly finding empty spot
    while (getOrganism(x, y) != nullptr) {
        x = rand() % GRIDSIZE;
        y = rand() % GRIDSIZE;
    }

    // returning the empty coordinates
    return {x, y};

}


// Function to count how many of a specific organism type there are left
int City::countType(char orgType) {

    int count = 0;

    for (auto & row : grid) {
        for  (auto & organism : row) {
            if (organism != nullptr && organism->getOrgType() == orgType) {
                count++;
            }
        }
    }

    return count;

}


// Function that returns true if there is at least one of each human and zombie
bool City::hasDiversity() {
    return countType(HUMAN_CH) > 0 && countType(ZOMBIE_CH) > 0;
}


std::ostream &operator<<(std::ostream &output, City &city) {

    // Outputting top of grid
    for (int i = 0; i < GRID_WIDTH; i++) {
        output << "___";
    }
    output << std::endl;

    // Looping through rows
    for (auto & row : city.grid) {
        output << "|";
        for (auto & organism : row) {

            if (organism == nullptr) {
                output << " " << EMPTY_CH << " ";
            } else {
                output << organism;
            }

        }
        output << "|" << std::endl;
    }

    // Outputting bottom of grid
    for (int i = 0; i < GRID_WIDTH; i++) {
        output << "‾‾‾";
    }
    output << std::endl;

    return output;

}


City::~City() = default;

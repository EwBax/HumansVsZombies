//
// Created by ewanb on 2023-04-13.
//

#include "../inc/Organism.h"
#include "../inc/City.h"

City::City() {

}

// Returns a pointer to the organism at coordinates x,y
Organism* City::getOrganism(int x, int y) {
    return grid[y][x];
}

// Sets the organism pointer at coordinates x,y
void City::setOrganism(Organism* organism, int x, int y) {
    grid[y][x] = organism;
}


// Iterates through the whole grid and moves each Organism, then iterates again and resets move flag
void City::move() {

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for  (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x]->turn();
        }
    }

}

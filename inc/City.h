//
// Created by ewanb on 2023-04-13.
//

#ifndef HUMANSVSZOMBIES_CITY_H
#define HUMANSVSZOMBIES_CITY_H

#include <iostream>
#include <array>

#include "GameSpecs.h"

class Organism;

const int GRID_WIDTH = GRIDSIZE;
const int GRID_HEIGHT = GRIDSIZE;

class City
{
private:
    int generation;

protected:
    Organism* grid[GRID_HEIGHT][GRID_WIDTH]{};

public:
    City();
    virtual ~City();

    Organism* getOrganism(int x, int y);
    void setOrganism(Organism *organism, int x, int y);
    void move();
    void reset();
    void spawnHumans();
    void spawnZombies();
    int countType(char orgType);
    bool hasDiversity();
    std::array<int, 2> findEmptySpot();

    int getGeneration() const {return generation;}

    friend std::ostream& operator<<(std::ostream &output, City &city);

};

#endif
 //HUMANSVSZOMBIES_CITY_H

//
// Created by ewanb on 2023-04-13.
//

#ifndef HUMANSVSZOMBIES_CITY_H
#define HUMANSVSZOMBIES_CITY_H

#include <iostream>

class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class City
{
protected:
    Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
    City();
    virtual ~City();

    Organism* getOrganism(int x, int y);
    void setOrganism(Organism *organism, int x, int y);

    void move();

    friend std::ostream& operator<<(std::ostream &output, City &city);

};
#endif
 //HUMANSVSZOMBIES_CITY_H

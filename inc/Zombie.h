//
// Created by ewanb on 2023-04-13.
//

#ifndef HUMANSVSZOMBIES_ZOMBIE_H
#define HUMANSVSZOMBIES_ZOMBIE_H

#include "Organism.h"

class Zombie : public Organism
{
protected:
    enum { WEST, NORTH_WEST, NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST,
            NUM_DIRECTIONS };

public:
    Zombie();
    Zombie(City* city, int x, int y) : Organism(city, x, y, ZOMBIE_CH) {};
    virtual ~Zombie();

    void move() override;
    void turn() override;
    std::vector<direction> findOpenDirections() override;
    direction pickDirection(std::vector<direction> openDirections) override;
};


#endif //HUMANSVSZOMBIES_ZOMBIE_H

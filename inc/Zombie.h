//
// Created by ewanb on 2023-04-13.
//

#ifndef HUMANSVSZOMBIES_ZOMBIE_H
#define HUMANSVSZOMBIES_ZOMBIE_H

#include "Organism.h"


class Zombie : public Organism
{
protected:
    int breedCounter;
    int starveCounter;

public:
    Zombie() = default;
    Zombie(City* city, int x, int y)
    : Organism(city, x, y, ZOMBIE_CH), breedCounter(0), starveCounter(0) {};
    ~Zombie() override = default;

    void move() override;
    void turn() override;
    bool breed();
    void starve();

    std::vector<direction> findOpenDirections() override;
    std::vector<direction> findHumanDirections();


};


#endif //HUMANSVSZOMBIES_ZOMBIE_H

//
// Created by ewanb on 2023-04-13.
//

#ifndef HUMANSVSZOMBIES_HUMAN_H
#define HUMANSVSZOMBIES_HUMAN_H

#include "Organism.h"
#include "GameSpecs.h"

class Human : public Organism
{
private:
    int recruitCounter;

public:
    Human();
    Human(City* city, int x, int y) :
    Organism(city, x, y, HUMAN_CH), recruitCounter(0) {}; ;
    virtual ~Human();

    void move() override;
    void turn() override;
    std::vector<direction> findOpenDirections() override;
    direction pickDirection(std::vector<direction> openDirections) override;

    void recruit();
};


#endif //HUMANSVSZOMBIES_HUMAN_H

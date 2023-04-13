//
// Created by ewanb on 2023-04-13.
//

#ifndef HUMANSVSZOMBIES_ORGANISM_H
#define HUMANSVSZOMBIES_ORGANISM_H

#include <iostream>
#include <vector>
#include <array>

#include "GameSpecs.h"
#include "City.h"

class Organism
{
protected:
    int x;
    int y;
    char orgType;
    bool hasMoved;
    City *city;

    enum {WEST, NORTH, EAST, SOUTH} typedef direction;

public:
    Organism();
    Organism(City* city, int x, int y, char orgType)
    : city(city), x(x), y(y), orgType(orgType), hasMoved(false) {};
    virtual ~Organism();

    virtual void move() = 0;
    virtual void turn() = 0;
    void resetHasMoved();
    //virtual void spawn() = 0;
    //virtual int getSpecies() = 0; //this could also be coded concrete here
    //virtual void getPosition() = 0;

    void setPosition(int newX, int newY);
    char getOrgType() const {return orgType;}
    void endTurn();
    bool isTurn();

    friend std::ostream& operator<<(std::ostream &output, Organism *organism);
};


#endif //HUMANSVSZOMBIES_ORGANISM_H

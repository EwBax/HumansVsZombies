//
// Created by ewanb on 2023-04-13.
//

#ifndef HUMANSVSZOMBIES_GAMESPECS_H
#define HUMANSVSZOMBIES_GAMESPECS_H

const int GRIDSIZE = 20; // size of the square grid
const int HUMAN_STARTCOUNT = 100; // initial Humans
const int ZOMBIE_STARTCOUNT = 5; //initial Zombie count
const int HUMAN_RECRUIT = 3; // steps until a Human breeds
const int ZOMBIE_BREED = 8; // steps until a Zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a Zombie starves and converts back
const char HUMAN_CH = 72;//72 "H"// ascii Human
const char EMPTY_CH = 45; // "-" ascii space
const char ZOMBIE_CH = 90;//90 "Z"// ascii zombie
const int INTERVAL = 1000; // pause between steps
const int ITERATIONS = 1000; // max number of steps

const int HUMAN_COLOR = 3; // Yellow
const int ZOMBIE_COLOR = 1; // Red
const int DEFAULT_COLOR = 0; // Black

#endif //HUMANSVSZOMBIES_GAMESPECS_H

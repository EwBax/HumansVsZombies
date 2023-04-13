//
// Created by ewanb on 2023-04-13.
//

#ifndef HUMANSVSZOMBIES_GAMESPECS_H
#define HUMANSVSZOMBIES_GAMESPECS_H

const int GRIDSIZE = 20; // size of the square grid
const int HUMAN_STARTCOUNT = 100; // inital Humans
const int ZOMBIE_STARTCOUNT = 5; //initial Zombie count
const int HUMAN_RECRUIT = 3; // steps until a Human breeds
const int ZOMBIE_BREED = 8; // steps until a Zombie breeds
const int ZOMBIE_STARVE = 3; // steps until a Zombie starves and converts back
const char HUMAN_CH = 72;//72 "H"// ascii Human
const char SPACE_CH = 32; // " " ascii space
const char ZOMBIE_CH = 90;//90 "Z"// ascii zombie
const int INTERVAL = 5000; // pause between steps
const int ITERATIONS = 1000; // max number of steps

//Colors
//0  = black				//9  = bright blue
//1  = blue					//10 = bright green
//2  = green				//11 = bright turquoise
//3  = turquise				//12 = bright red
//4  = red					//13 = bright pink
//5  = pink					//14 = bright yellow
//6  = yellow				//15 = bright white
//7  = white regular		//16+ = solid blocks
//8  = white pale

const int HUMAN_COLOR = 3; // turquoise
const int ZOMBIE_COLOR = 14; // bright yellow

#endif //HUMANSVSZOMBIES_GAMESPECS_H

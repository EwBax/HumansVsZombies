#include <iostream>
#include <chrono>
#include <thread>

#include "inc/Organism.h"
#include "inc/City.h"
#include "inc/GameSpecs.h"

using namespace std;

static int INTERVAL = 5000;

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    City *city = new City();
    chrono:: milliseconds interval(INTERVAL);

    while (city->hasDiversity()) { //while both humans and zombies exist
        this_thread::sleep_for(interval);
        ClearScreen();
        city->move(); //includes all actions


// Alternate multi-pass version with each activity happening in its own
// pass through the array. Lends itself to prototyping and testing:
        //   city->humansMove();
        //   city->zombiesMoveEat();
        //   city->humansRecruit();
        //   city->zombiesRecruit();
        //   city->zombiesStarve();
        //   city->countOrganisms(Z or H goes here);

        city->reset(); //resets moved flags
        city->countOrganisms(Z or H goes here);// run once for each type
        cout << *city; //prints city
        cout << "GENERATION " << city->getGeneration() << endl;
        cout << "HUMANS: " << city->countType(HUMAN_CH) << endl;
        cout << "ZOMBIES: " << city->countType(ZOMBIE_CH) << endl;
    }//end while
}//end main

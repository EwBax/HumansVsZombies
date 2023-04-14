#include <iostream>
#include <chrono>
#include <thread>

#include "inc/Organism.h"
#include "inc/City.h"
#include "inc/GameSpecs.h"

using namespace std;

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {

    City *city = new City();

    chrono:: milliseconds interval(INTERVAL);

    while (city->hasDiversity() && city->getGeneration() < ITERATIONS) { //while both humans and zombies
        // exist

        this_thread::sleep_for(interval);

        ClearScreen();

        cout << *city; //prints city
        cout << "GENERATION " << city->getGeneration() << endl;
        cout << "HUMANS: " << city->countType(HUMAN_CH) << endl;
        cout << "ZOMBIES: " << city->countType(ZOMBIE_CH) << endl;

        city->move(); //includes all actions
        city->reset(); //resets moved flags

    }//end while

}//end main

/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 2
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "studyInPink3a.h"

using namespace std;

int main(int argc, const char * argv[]) {
	
Character chMurderer("**Murderer**");
    chMurderer.moveToPoint(1, 3);
    chMurderer.moveToPoint(1, 5);
    chMurderer.moveToPoint(1, 7);

    Character chWatson("Watson");
    chWatson.moveToPoint(1, 2);
    chWatson.moveToPoint(1, 4);

    int outDistance = -2;
    int maxLength = 3;
    int maxDistance = 5;

    cout << "--- maxDistance: " << maxDistance << endl;
    cout << "Can rescue: " << rescueSherlock(chMurderer, chWatson, maxLength, maxDistance, outDistance) << endl;
    cout << "outDistance: " << outDistance << endl;

    maxDistance = 2;
    cout << "--- maxDistance: " << maxDistance << endl;
    cout << "Can rescue: " << rescueSherlock(chMurderer, chWatson, maxLength, maxDistance, outDistance) << endl;
    cout << "outDistance: " << outDistance << endl;

    maxLength = 1;
    cout << "--- maxLength: " << maxLength << endl;
    cout << "Can rescue: " << rescueSherlock(chMurderer, chWatson, maxLength, maxDistance, outDistance) << endl;
    cout << "outDistance: " << outDistance << endl;

    return 0;
}
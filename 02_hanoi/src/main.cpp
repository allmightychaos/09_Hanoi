#include <iostream>
#include "tower.h"

using namespace std;

void move(Tower &start, Tower &ziel, Tower &zwischenspeicher, int anzahl_der_scheiben, int &counter)
{
    if (anzahl_der_scheiben == 1) {
        ziel.push(start.pop());
        counter++;
    }
    else {
        move(start, zwischenspeicher, ziel, anzahl_der_scheiben - 1, counter);
        ziel.push(start.pop());
        counter++;
        move(zwischenspeicher, ziel, start, anzahl_der_scheiben - 1, counter);
    }
}

int main(int, char**) {
    Tower t1("Start", 8, true);
    Tower t2("Frei", 8, false);
    Tower t3("Ziel", 8, false);
    system("clear");
    t1.print(1, 0);
    t2.print(13, 0);
    t3.print(25, 0);
    int counter = 0; // Initialize the counter variable
    try
    {
        move(t1, t3, t2, 8, counter);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    t1.print(1, 12);
    t2.print(13, 12);
    t3.print(25, 12);

    if (counter < 60) {
        cout << "\n\nEs würde " << counter << " Sekunden dauern." << endl;
    } 
    else if (counter < 3600) {
        cout << "\n\nEs würde " << counter / 60 << " Minuten und " << counter % 60 << " Sekunden dauern." << endl;
    }
    else {
        cout << "\n\nEs würde " << counter / 3600 << " Stunden, " << (counter % 3600) / 60 << " Minuten und " << counter % 60 << " Sekunden dauern." << endl;
    }

}

#include <iostream>
#include "tower.h"

using namespace std;

void move(Tower &start, Tower &ziel, Tower &zwischenspeicher, int anzahl_der_scheiben)
{
    //hier den Inhalt der rekursiven Funktion vervollständigen
    //push legt eine Scheibe auf den Stapel
    //pop nimmt eine Scheibe von dem Stapel
    
    if (anzahl_der_scheiben == 1) {
        ziel.push(start.pop());
    }
    else {
        move(start, zwischenspeicher, ziel, anzahl_der_scheiben - 1);
        ziel.push(start.pop());
        move(zwischenspeicher, ziel, start, anzahl_der_scheiben - 1);
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
    try
    {
        move(t1, t3, t2, 8);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    t1.print(1, 12);
    t2.print(13, 12);
    t3.print(25, 12);
}

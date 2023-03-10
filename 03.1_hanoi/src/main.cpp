#include <iostream>
#include <chrono>
#include <thread>
#include "tower.h"

using namespace std;

void move(Tower &start, Tower &ziel, Tower &zwischenspeicher, int anzahl_der_scheiben, int anzahl_bewegungen, int &counter, Tower &t1, Tower &t2, Tower &t3, int zeit)
{
    if (anzahl_der_scheiben == 1) {
        ziel.push(start.pop());
        counter++;
        if (counter % anzahl_bewegungen == 0) {
            system("clear");
            t1.print(1, 0);
            t2.print(13, 0);
            t3.print(25, 0);
            cout << "\n\nAnzahl der Bewegungen: " << counter << endl;
            this_thread::sleep_for(chrono::milliseconds(zeit));
        }
    }
    else {
        move(start, zwischenspeicher, ziel, anzahl_der_scheiben - 1, anzahl_bewegungen, counter, t1, t2, t3, zeit);
        ziel.push(start.pop());
        counter++;
        if (counter % anzahl_bewegungen == 0) {
            system("clear");
            t1.print(1, 0);
            t2.print(13, 0);
            t3.print(25, 0);
            cout << "\n\nAnzahl der Bewegungen: " << counter << endl;
            this_thread::sleep_for(chrono::milliseconds(zeit));
        }
        move(zwischenspeicher, ziel, start, anzahl_der_scheiben - 1, anzahl_bewegungen, counter, t1, t2, t3, zeit);
    }
}

int main(int argc, char** argv) {
    system("clear");
    int anzahl_bewegungen;
    int zeit;

    if (argc < 2) {
        cout << "Bitte geben Sie die Anzahl der Bewegungen an.\n> ";
        cin >> anzahl_bewegungen;
        cout << "Bitte geben Sie die Zeit in Millisekunden an.\n> ";
        cin >> zeit;
    }
    else if (argc = 2) {
        anzahl_bewegungen = stoi(argv[1]);
        cout << "Bitte geben Sie die Zeit in Millisekunden an.\n> ";
        cin >> zeit;
    }
    else {
        anzahl_bewegungen = stoi(argv[1]);
        zeit = stoi(argv[2]);
    }

    Tower t1("Start", 8, true);
    Tower t2("Frei", 8, false);
    Tower t3("Ziel", 8, false);
    system("clear");
    t1.print(1, 0);
    t2.print(13, 0);
    t3.print(25, 0);

    int counter = 1;
    try {
        move(t1, t3, t2, 8, anzahl_bewegungen, counter, t1, t2, t3, zeit);
    }
    catch(const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    system("clear");
    t1.print(1, 0);
    t2.print(13, 0);
    t3.print(25, 0);
    
    cout << "\n\nAnzahl der Bewegungen: " << counter << endl;
    if (counter < 60) {
        cout << "Es w??rde " << counter << " Sekunden dauern." << endl;
    } 
    else if (counter < 3600) {
        cout << "Es w??rde " << counter / 60 << " Minuten und " << counter % 60 << " Sekunden dauern." << endl;
    }
    else {
        cout << "Es w??rde " << counter / 3600 << " Stunden, " << (counter % 3600) / 60 << " Minuten und " << counter % 60 << " Sekunden dauern." << endl;
    }
}

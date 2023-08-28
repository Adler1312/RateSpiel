#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));  

    int secretNumber = rand() % 100 + 1; 
    int guess;
    int attempts = 0;

    std::cout << "Willkommen bei 'Rate die Zahl'!" << std::endl;

    do {
        std::cout << "Gib eine Zahl zwischen 1 und 100 ein: ";
        std::cin >> guess;

        attempts++;

        if (guess > secretNumber) {
            std::cout << "Zu hoch! Versuche es erneut." << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Zu niedrig! Versuche es erneut." << std::endl;
        } else {
            std::cout << "Richtig geraten! Die geheime Zahl war " << secretNumber << "." << std::endl;
            std::cout << "Du hast " << attempts << " Versuch(e) gebraucht." << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}

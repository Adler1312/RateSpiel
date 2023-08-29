#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    int secretNumber, guess, attempts = 0;
    int maxAttempts = 10;
    bool playAgain = true;

    std::cout << "Willkommen bei 'Rate die Zahl'!" << std::endl;

    while (playAgain) {
        char difficulty;
        std::cout << "Waehle eine Schwierigkeitsstufe: (e)infach, (m)ittel, (s)chwer: ";
        std::cin >> difficulty;

        int minRange, maxRange;

        switch (difficulty) {
            case 'e':
                minRange = 1;
                maxRange = 50;
                break;
            case 'm':
                minRange = 1;
                maxRange = 100;
                break;
            case 's':
                minRange = 1;
                maxRange = 200;
                break;
            default:
                std::cout << "Ungueltige Eingabe. Standardmaessig wird mittlere Schwierigkeit gewaehlt." << std::endl;
                minRange = 1;
                maxRange = 100;
                break;
        }

        secretNumber = rand() % maxRange + minRange;
        attempts = 0;

        std::cout << "Ich habe eine neue Zahl gewaehlt. Du hast " << maxAttempts << " Versuche." << std::endl;

        do {
            std::cout << "Gib eine Zahl zwischen " << minRange << " und " << maxRange << " ein: ";
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

            if (attempts >= maxAttempts) {
                std::cout << "Du hast keine Versuche mehr. Die geheime Zahl war " << secretNumber << "." << std::endl;
                break;
            }

        } while (guess != secretNumber);

        char playAgainResponse;
        std::cout << "Moechtest du noch einmal spielen? (j/n): ";
        std::cin >> playAgainResponse;
        playAgain = (playAgainResponse == 'j' || playAgainResponse == 'J');
    }

    std::cout << "Vielen Dank fuer's Spielen!" << std::endl;

    return 0;
}

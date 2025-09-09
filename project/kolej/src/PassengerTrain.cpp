/**
 * @file PassengerTrain.cpp
 * @brief Implementacja metod klasy PassengerTrain, reprezentującej pociąg pasażerski.
 * @authors Hanna Mikołajczyk, Adrian Tameczka
 * @date 11.06.2025
 */

#include "../include/model/PassengerTrain.h"

/**
 * @brief Konstruktor klasy PassengerTrain.
 *
 * Inicjalizuje klasę bazową Train z podanymi danymi.
 *
 * @param name Nazwa pociągu.
 * @param trainNumber Numer pociągu.
 * @param seats Liczba miejsc siedzących.
 */
PassengerTrain::PassengerTrain(const std::string& name, int trainNumber, int seats)
    : Train(name, trainNumber, seats) {}

/**
 * @brief Wirtualny destruktor klasy PassengerTrain.
 */
PassengerTrain::~PassengerTrain() {}

/**
 * @brief Zwraca sformatowaną informację o pociągu pasażerskim.
 *
 * @return Tekst zawierający nazwę, numer i liczbę miejsc w pociągu.
 */
std::string PassengerTrain::getInfo() const {
    return "Pociąg pasażerski:\n--> Nazwa: " + getName() +
           "\n--> Numer: " + std::to_string(getTrainNumber()) +
           "\n--> Miejsca: " + std::to_string(getSeats());
}

/**
 * @brief Zwraca liczbę dostępnych miejsc w pociągu.
 *
 * @return Liczba miejsc siedzących.
 */
int PassengerTrain::getAvailableSeats() const {
    return getSeats();
}

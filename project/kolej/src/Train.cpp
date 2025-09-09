/**
 * @file Train.cpp
 * @brief Implementacja klasy Train reprezentującej pociąg.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#include "../include/model/Train.h"

/**
 * @brief Konstruktor klasy Train.
 *
 * Inicjalizuje pociąg z podaną nazwą, numerem pociągu i liczbą miejsc.
 * Ustawia liczbę dostępnych miejsc na taką samą jak całkowita liczba miejsc.
 * @param name Nazwa pociągu.
 * @param trainNumber Numer pociągu.
 * @param seats Całkowita liczba miejsc w pociągu.
 */
Train::Train(std::string name, int trainNumber, int seats)
    : name(name), trainNumber(trainNumber), seats(seats), availableSeats(seats) {}

/**
 * @brief Destruktor klasy Train.
 */
Train::~Train() {}

/**
 * @brief Pobiera nazwę pociągu.
 * @return Nazwa pociągu jako std::string.
 */
std::string Train::getName() const {
    return name;
}

/**
 * @brief Pobiera numer pociągu.
 * @return Numer pociągu jako int.
 */
int Train::getTrainNumber() const {
    return trainNumber;
}

/**
 * @brief Pobiera całkowitą liczbę miejsc w pociągu.
 * @return Liczba miejsc jako int.
 */
int Train::getSeats() const {
    return seats;
}

/**
 * @brief Pobiera liczbę dostępnych miejsc w pociągu.
 * @return Liczba dostępnych miejsc jako int.
 */
int Train::getAvailableSeats() const {
    return availableSeats;
}

/**
 * @brief Ustawia całkowitą liczbę miejsc w pociągu.
 * @param seats Nowa liczba miejsc.
 */
void Train::setSeats(int seats) {
    this->seats = seats;
}

/**
 * @brief Ustawia numer pociągu.
 * @param trainNumber Nowy numer pociągu.
 */
void Train::setTrainNumber(int trainNumber) {
    this->trainNumber = trainNumber;
}

/**
 * @brief Ustawia nazwę pociągu.
 * @param name Nowa nazwa pociągu.
 */
void Train::setName(const std::string& name) {
    this->name = name;
}

/**
 * @brief Ustawia liczbę dostępnych miejsc w pociągu.
 * @param availableSeats Nowa liczba dostępnych miejsc.
 */
void Train::setAvailableSeats(int availableSeats) {
    this->availableSeats = availableSeats;
}

/**
 * @brief Przydziela miejsca w pociągu.
 *
 * Jeśli dostępne są miejsca, zmniejsza liczbę dostępnych miejsc o 1 i zwraca potwierdzenie.
 * W przeciwnym razie zwraca informację o braku miejsc.
 * @return Informacja o przydzielonych miejscach jako std::string.
 */
std::string Train::assignSeats() {
    if (availableSeats > 0) {
        availableSeats--;
        return "Pomyślnie zarezerwowano miejsce.";
    }
    return "Brak dostępnych miejsc.";
}
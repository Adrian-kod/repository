/**
 * @file GoodsTrain.cpp
 * @brief Implementacja klasy GoodsTrain reprezentującej pociąg towarowy.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#include "../include/model/GoodsTrain.h"

/**
 * @brief Konstruktor klasy GoodsTrain.
 *
 * Inicjalizuje pociąg towarowy z podaną nazwą, numerem, liczbą miejsc, aktualnym i maksymalnym ładunkiem.
 * @param name Nazwa pociągu.
 * @param trainNumber Numer pociągu.
 * @param seats Całkowita liczba miejsc w pociągu.
 * @param courrentLoadKg Aktualny ładunek w kilogramach (literówka: powinno być currentLoadKg).
 * @param maxLoadKg Maksymalny ładunek w kilogramach.
 */
GoodsTrain::GoodsTrain(const std::string& name, int trainNumber, int seats, double currentLoadKg, double maxLoadKg)
    : Train(name, trainNumber, seats), currentLoadKg(currentLoadKg), maxLoadKg(maxLoadKg) {}

/**
 * @brief Destruktor klasy GoodsTrain.
 */
GoodsTrain::~GoodsTrain() {}

/**
 * @brief Pobiera liczbę dostępnych miejsc w pociągu.
 *
 * Zwraca 0, ponieważ pociąg towarowy nie oferuje miejsc dla pasażerów.
 * @return Liczba dostępnych miejsc jako int (zawsze 0).
 */
int GoodsTrain::getAvailableSeats() const {
    return 0;
}

/**
 * @brief Pobiera aktualny ładunek pociągu.
 * @return Aktualny ładunek w kilogramach jako double.
 */
double GoodsTrain::getCurrentLoadKg() const {
    return currentLoadKg;
}

/**
 * @brief Pobiera maksymalny ładunek pociągu.
 * @return Maksymalny ładunek w kilogramach jako double.
 */
double GoodsTrain::getMaxLoadKg() const {
    return maxLoadKg;
}

/**
 * @brief Pobiera informacje o pociągu towarowym.
 *
 * Zwraca ciąg znaków zawierający nazwę, numer, maksymalny i aktualny ładunek pociągu.
 * @return Informacje o pociągu jako std::string.
 */
std::string GoodsTrain::getInfo() const {
    return "Pociąg towarowy:\n--> Nazwa: " + getName() +
           "\n--> Numer: " + std::to_string(getTrainNumber()) +
           "\n--> Maksymalna pojemność: " + std::to_string(getMaxLoadKg()) +
           "\n--> Aktualna pojemność: " + std::to_string(getCurrentLoadKg());
}

/**
 * @brief Ładuje towar na pociąg.
 *
 * Dodaje podaną wagę do aktualnego ładunku, jeśli nie przekracza maksymalnego ładunku.
 * @param weight Waga towaru do załadowania w kilogramach.
 * @return Wartość logiczna wskazująca, czy załadunek się powiódł.
 */
bool GoodsTrain::loadCargo(int weight) {
    if (currentLoadKg + weight <= maxLoadKg) {
        currentLoadKg += weight;
        return true;
    }
    return false;
}
/**
 * @file LargeGoodsTrain.cpp
 * @brief Implementacja klasy LargeGoodsTrain reprezentującej duży pociąg towarowy.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#include "../include/model/LargeGoodsTrain.h"

/**
 * @brief Konstruktor klasy LargeGoodsTrain.
 *
 * Inicjalizuje duży pociąg towarowy z podaną nazwą, numerem, liczbą miejsc, aktualnym i maksymalnym ładunkiem.
 * Wywołuje konstruktor klasy bazowej GoodsTrain.
 * @param name Nazwa pociągu.
 * @param trainNumber Numer pociągu.
 * @param seats Całkowita liczba miejsc w pociągu.
 * @param courrentLoadKg Aktualny ładunek w kilogramach (literówka: powinno być currentLoadKg).
 * @param maxLoadKg Maksymalny ładunek w kilogramach.
 */
LargeGoodsTrain::LargeGoodsTrain(const std::string& name, int trainNumber, int seats, double currentLoadKg, double maxLoadKg)
    : GoodsTrain(name, trainNumber, seats, currentLoadKg, maxLoadKg) {}

/**
 * @brief Destruktor klasy LargeGoodsTrain.
 */
LargeGoodsTrain::~LargeGoodsTrain() {}

/**
 * @brief Pobiera informacje o dużym pociągu towarowym.
 *
 * Zwraca ciąg znaków zawierający nazwę, numer, liczbę miejsc, maksymalny i aktualny ładunek pociągu.
 * @return Informacje o pociągu jako std::string.
 */
std::string LargeGoodsTrain::getInfo() const {
    return "Pociąg towarowy (gabaryty):\n--> " + getName() +
           "\n--> Numer: " + std::to_string(getTrainNumber()) +
           "\n--> Miejsca: " + std::to_string(getSeats()) +
           "\n--> Maksymalna pojemność: " + std::to_string(getMaxLoadKg()) +
           "\n--> Aktualna pojemność: " + std::to_string(getCurrentLoadKg());
}


/**
 * @file LuxuryGoodsTrain.cpp
 * @brief Implementacja metod klasy LuxuryGoodsTrain reprezentującej luksusowy pociąg towarowy.
 * @authors Hanna Mikołajczyk, Adrian Tameczka
 * @date 11.06.2025
 */

#include "../include/model/LuxuryGoodsTrain.h"

/**
 * @brief Konstruktor klasy LuxuryGoodsTrain.
 *
 * Inicjalizuje obiekt klasy bazowej GoodsTrain oraz ustawia status ochrony.
 *
 * @param name Nazwa pociągu.
 * @param trainNumber Numer identyfikacyjny pociągu.
 * @param seats Liczba miejsc w pociągu.
 * @param courrentLoadKg Aktualne obciążenie w kilogramach.
 * @param maxLoadKg Maksymalne obciążenie w kilogramach.
 * @param securityEnabled Czy ochrona została włączona przy tworzeniu.
 */
LuxuryGoodsTrain::LuxuryGoodsTrain(const std::string& name, int trainNumber, int seats, double currentLoadKg, double maxLoadKg, bool securityEnabled)
    : GoodsTrain(name, trainNumber, seats, currentLoadKg, maxLoadKg), securityEnabled(securityEnabled) {}

/**
 * @brief Aktywuje system ochrony pociągu.
 *
 * Ustawia flagę `securityEnabled` na true.
 */
void LuxuryGoodsTrain::enableSecurity() {
    securityEnabled = true;
}

/**
 * @brief Zwraca informacje o pociągu, w tym status ochrony.
 *
 * Informacja zawiera nazwę, numer, miejsca, pojemność oraz status ochrony.
 *
 * @return Sformatowany tekst z danymi pociągu.
 */
std::string LuxuryGoodsTrain::getInfo() const {
    return "Pociąg towarowy (towary wartościowe): " + getName() +
           "\n--> Numer: " + std::to_string(getTrainNumber()) +
           "\n--> Miejsca: " + std::to_string(getSeats()) +
           "\n--> Maksymalna pojemność: " + std::to_string(getMaxLoadKg()) +
           "\n--> Aktualna pojemność: " + std::to_string(getCurrentLoadKg()) +
           "\n--> Wykupione ubezpieczenie: " + (securityEnabled ? " [Secured]" : " [Unsecured]");
}


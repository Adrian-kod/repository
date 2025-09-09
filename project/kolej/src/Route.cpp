/**
 * @file Route.cpp
 * @brief Implementacja metod klasy Route, reprezentującej trasę kolejową.
 * @authors Hanna Mikołajczyk, Adrian Tameczka
 * @date 09.06.2025
 */

#include "../include/model/Route.h"

/**
 * @brief Konstruktor klasy Route.
 *
 * Sprawdza poprawność danych wejściowych i ustawia pola trasy.
 *
 * @param first Nazwa stacji początkowej.
 * @param last Nazwa stacji końcowej.
 * @param duration Czas trwania przejazdu (w godzinach).
 * @param stations Liczba stacji w formie tekstowej.
 *
 * @throws std::invalid_argument jeśli dane są niepoprawne:
 * - stacje są puste lub takie same,
 * - czas trwania jest niedodatni,
 * - liczba stacji jest pusta lub nieokreślona.
 */
Route::Route(const std::string& firstStation, const std::string& lastStation, double duration, const std::string& numberOfStations):firstStation (firstStation), lastStation (lastStation), duration (duration), numberOfStations (numberOfStations) {
    if (firstStation.empty() || lastStation.empty()) {
        throw std::invalid_argument("Nazwy stacji nie mogą być puste");
    }
    if (firstStation == lastStation) {
        throw std::invalid_argument("Pierwsza i ostatnia stacja nie mogą być takie same");
    }
    if (duration <= 0) {
        throw std::invalid_argument("Czas trwania trasy musi być dodatni");
    }
    if (numberOfStations.empty() || numberOfStations == "-1") {
        throw std::invalid_argument("Ilość stacji musi być określona i nie może być pusta");
    }
	this->firstStation = firstStation;
	this->lastStation = lastStation;
	this->numberOfStations = numberOfStations;
    this->duration = duration;
}

/**
 * @brief Wirtualny destruktor klasy Route.
 */
Route::~Route() {}

/**
 * @brief Zwraca nazwę stacji początkowej.
 * @return Nazwa pierwszej stacji.
 */
std::string Route::getFirstStation() const {
    return firstStation;
}

/**
 * @brief Zwraca nazwę stacji końcowej.
 * @return Nazwa ostatniej stacji.
 */
std::string Route::getLastStation() const {
    return lastStation;
}

/**
 * @brief Zwraca czas trwania przejazdu.
 * @return Czas w godzinach.
 */
double Route::getDuration() const {
    return duration;
}

/**
 * @brief Zwraca tekstowy opis liczby stacji.
 * @return Liczba stacji w formie tekstowej.
 */
std::string Route::getNumberOfStations() const {
    return numberOfStations;
}

/**
 * @brief Ustawia nową stację początkową.
 * @param firstStation Nazwa nowej stacji początkowej.
 */
void Route::setFirstStation(const std::string& firstStation) {
    this->firstStation = firstStation;
}

/**
 * @brief Ustawia nową stację końcową.
 * @param lastStation Nazwa nowej stacji końcowej.
 */
void Route::setLastStation(const std::string& lastStation) {
    this->lastStation = lastStation;
}

/**
 * @brief Ustawia czas trwania trasy.
 *
 * @param duration Nowy czas w godzinach.
 * @throws std::invalid_argument jeśli wartość jest mniejsza lub równa 0.
 */
void Route::setDuration(double duration) {
    if (duration <= 0) {
        throw std::invalid_argument("Czas trwania trasy musi być dodatni");
    }
    this->duration = duration;
}

/**
 * @brief Ustawia opis liczby stacji.
 *
 * @param numberOfStations Nowy opis liczby stacji.
 * @throws std::invalid_argument jeśli wartość jest pusta lub nieprawidłowa.
 */
void Route::setNumberOfStations(const std::string& numberOfStations) {
    if (numberOfStations.empty() || numberOfStations == "-1") {
        throw std::invalid_argument("Ilość stacji musi być określona i nie może być pusta");
    }
    this->numberOfStations = numberOfStations;
}

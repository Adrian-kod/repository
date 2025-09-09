/**
 * @file TrainManager.cpp
 * @brief Implementacja klasy TrainManager zarządzającej kolekcją pociągów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#include "../include/model/TrainManager.h"
// Uwaga: Linia #include "../include/model" została usunięta, ponieważ jest niepoprawna (prawdopodobnie chodziło o konkretny plik nagłówkowy).

/**
 * @brief Konstruktor domyślny klasy TrainManager.
 *
 * Inicjalizuje pusty wektor pociągów.
 */
TrainManager::TrainManager() : trains() {}

/**
 * @brief Destruktor klasy TrainManager.
 */
TrainManager::~TrainManager() {}

/**
 * @brief Tworzy nowy pociąg i dodaje go do kolekcji.
 *
 * Dodaje podane pociągi do wektora trains, jeśli dane wejściowe są prawidłowe.
 * @param trains Wektor pociągów do dodania.
 * @param clients Wektor klientów (nieużywany w obecnej implementacji).
 * @return Wartość logiczna wskazująca, czy operacja się powiodła (true, jeśli wektory nie są puste).
 */
bool TrainManager::createTrain(std::vector<TrainPtr> trains, std::vector<TrainPtr> clients) {
    // Walidacja danych wejściowych
    if (trains.empty() || clients.empty()) {
        return false;
    }

    // Sprawdzenie, czy wszystkie pociągi są unikalne
    this->trains.insert(this->trains.end(), trains.begin(), trains.end());
    return true;
}

/**
 * @brief Zlicza liczbę pociągów w kolekcji.
 * @return Liczba pociągów jako int.
 */
int TrainManager::countTrains() const {
    return static_cast<int>(trains.size());
}
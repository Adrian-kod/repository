/**
 * @file TrainManager.h
 * @brief Definicja klasy TrainManager zarządzającej kolekcją pociągów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#ifndef TRAINMANAGER_H
#define TRAINMANAGER_H

#include "../typedefs.h"
#include <vector>
#include <memory>

/**
 * @class TrainManager
 * @brief Klasa zarządzająca kolekcją pociągów.
 *
 * Klasa TrainManager przechowuje listę wskaźników do obiektów typu Train i udostępnia
 * metody do zarządzania pociągami, takie jak tworzenie nowych pociągów oraz zliczanie ich liczby.
 */
class TrainManager {
private:
    std::vector<TrainPtr> trains; ///< Wektor przechowujący wskaźniki do obiektów typu Train.

public:
    /**
     * @brief Konstruktor domyślny klasy TrainManager.
     */
    TrainManager();

    /**
     * @brief Destruktor klasy TrainManager.
     */
    ~TrainManager();

    /**
     * @brief Tworzy nowy pociąg i dodaje go do kolekcji.
     * @param trains Wektor pociągów do dodania.
     * @param clients Wektor klientów (nieużywany w obecnej implementacji).
     * @return Wartość logiczna wskazująca, czy operacja się powiodła.
     */
    bool createTrain(std::vector<TrainPtr> trains, std::vector<TrainPtr> clients);

    /**
     * @brief Zlicza liczbę pociągów w kolekcji.
     * @return Liczba pociągów jako int.
     */
    int countTrains() const;
};

#endif //TRAINMANAGER_H

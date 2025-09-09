/**
 * @file TrainRepository.h
 * @brief Definicja klasy TrainRepository zarządzającej repozytorium pociągów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#ifndef TRAINREPOSITORY_H
#define TRAINREPOSITORY_H

#include "Train.h"
#include <vector>
#include <memory>

/**
 * @class TrainRepository
 * @brief Klasa zarządzająca repozytorium pociągów.
 *
 * Klasa TrainRepository dostarcza metody do dodawania i usuwania pociągów z wektora przechowującego wskaźniki do obiektów typu Train.
 */
class TrainRepository {
public:
    /**
     * @brief Dodaje pociąg do wektora pociągów.
     * @param train Pociąg do dodania.
     * @param trains Wektor przechowujący wskaźniki do obiektów typu Train.
     */
    void addTrain(const Train& train, std::vector<TrainPtr>& trains);

    /**
     * @brief Usuwa pociąg z wektora pociągów.
     * @param train Pociąg do usunięcia.
     * @param trains Wektor przechowujący wskaźniki do obiektów typu Train.
     */
    void removeTrain(const Train& train, std::vector<TrainPtr>& trains);
};

#endif //TRAINREPOSITORY_H

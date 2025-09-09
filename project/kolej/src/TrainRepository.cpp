/**
 * @file TrainRepository.cpp
 * @brief Implementacja klasy TrainRepository zarządzającej repozytorium pociągów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#include "../include/model/TrainRepository.h"
#include <algorithm>
// Uwaga: Linia #include "../include/model/" została usunięta, ponieważ jest niepoprawna (prawdopodobnie chodziło o konkretny plik nagłówkowy, np. Train.h).

/**
 * @brief Dodaje pociąg do wektora pociągów.
 *
 * Tworzy nowy współdzielony wskaźnik do kopii podanego pociągu i dodaje go do wektora.
 * @param train Pociąg do dodania.
 * @param trains Wektor przechowujący wskaźniki do obiektów typu Train.
 */
void TrainRepository::addTrain(const Train& train, std::vector<TrainPtr>& trains) {
    trains.push_back(std::make_shared<Train>(train));
}

/**
 * @brief Usuwa pociąg z wektora pociągów.
 *
 * Usuwa wszystkie pociągi z wektora, których numer pociągu zgadza się z numerem podanego pociągu.
 * @param train Pociąg do usunięcia.
 * @param trains Wektor przechowujący wskaźniki do obiektów typu Train.
 */
void TrainRepository::removeTrain(const Train& train, std::vector<TrainPtr>& trains) {
    trains.erase(
        std::remove_if(trains.begin(), trains.end(),
            [&train](const TrainPtr& t) {
                return t->getTrainNumber() == train.getTrainNumber();
            }),
        trains.end()
    );
}
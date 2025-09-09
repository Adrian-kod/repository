/**
 * @file PassengerTrain.h
 * @brief Deklaracja klasy PassengerTrain, reprezentującej pociąg pasażerski.
 * @authors Hanna Mikołajczyk, Adrian Tameczka
 * @date 11.06.2025
 */

#ifndef PASSENGERTRAIN_H
#define PASSENGERTRAIN_H

#include "Train.h"

/**
 * @class PassengerTrain
 * @brief Klasa reprezentująca pociąg pasażerski, dziedzicząca po klasie Train.
 *
 * Dodaje funkcję zwracającą liczbę dostępnych miejsc oraz własną wersję `getInfo()`.
 * Klasa jest abstrakcyjna (zawiera czysto wirtualny destruktor).
 */
class PassengerTrain : public Train {
public:
    /**
     * @brief Konstruktor klasy PassengerTrain.
     *
     * @param name Nazwa pociągu.
     * @param trainNumber Numer pociągu.
     * @param seats Liczba dostępnych miejsc siedzących.
     */
    PassengerTrain(const std::string& name, int trainNumber, int seats);

    /**
     * @brief Wirtualny destruktor czysto wirtualny (klasa abstrakcyjna).
     */
    virtual ~PassengerTrain();

    /**
     * @brief Zwraca informacje tekstowe o pociągu pasażerskim.
     *
     * @return Sformatowany opis pociągu.
     */
    std::string getInfo() const override;

    /**
     * @brief Zwraca liczbę dostępnych miejsc siedzących.
     *
     * @return Liczba wolnych miejsc.
     */
    int getAvailableSeats() const override;
};

#endif // PASSENGERTRAIN_H


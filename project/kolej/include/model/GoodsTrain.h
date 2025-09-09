/**
 * @file GoodsTrain.h
 * @brief Definicja klasy GoodsTrain reprezentującej pociąg towarowy.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#ifndef GOODSTRAIN_H
#define GOODSTRAIN_H

#include "Train.h"

/**
 * @class GoodsTrain
 * @brief Klasa reprezentująca pociąg towarowy, dziedzicząca po Train.
 *
 * Klasa GoodsTrain przechowuje informacje o pociągu towarowym, takie jak aktualny i maksymalny ładunek.
 * Dziedziczy po klasie bazowej Train i dostarcza własną implementację metod wirtualnych.
 */
class GoodsTrain : public Train {
private:
    double currentLoadKg; ///< Aktualny ładunek w kilogramach (literówka: powinno być currentLoadKg).
    double maxLoadKg; ///< Maksymalny ładunek w kilogramach.

public:
    /**
     * @brief Konstruktor klasy GoodsTrain.
     * @param name Nazwa pociągu.
     * @param trainNumber Numer pociągu.
     * @param seats Całkowita liczba miejsc w pociągu.
     * @param courrentLoadKg Aktualny ładunek w kilogramach.
     * @param maxLoadKg Maksymalny ładunek w kilogramach.
     */
    GoodsTrain(const std::string& name, int trainNumber, int seats, double currentLoadKg, double maxLoadKg);

    /**
     * @brief Czysto wirtualny destruktor klasy GoodsTrain.
     */
    virtual ~GoodsTrain() = 0;

    /**
     * @brief Pobiera liczbę dostępnych miejsc w pociągu.
     * @return Liczba dostępnych miejsc jako int.
     */
    int getAvailableSeats() const override;

    /**
     * @brief Pobiera aktualny ładunek pociągu.
     * @return Aktualny ładunek w kilogramach jako double.
     */
    double getCurrentLoadKg() const;

    /**
     * @brief Pobiera maksymalny ładunek pociągu.
     * @return Maksymalny ładunek w kilogramach jako double.
     */
    double getMaxLoadKg() const;

    /**
     * @brief Pobiera informacje o pociągu towarowym.
     * @return Informacje o pociągu jako std::string.
     */
    std::string getInfo() const override;

    /**
     * @brief Ładuje towar na pociąg.
     * @param weight Waga towaru do załadowania w kilogramach.
     * @return Wartość logiczna wskazująca, czy załadunek się powiódł.
     */
    bool loadCargo(int weight);
};

#endif //GOODSTRAIN_H

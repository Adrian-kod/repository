/**
 * @file LargeGoodsTrain.h
 * @brief Deklaracja klasy LargeGoodsTrain, reprezentującej duży pociąg towarowy.
 * @authors Hanna Mikołajczyk, Adrian Tameczka
 * @date 11.06.2025
 */

#ifndef LARGEGOODSTRAIN_H
#define LARGEGOODSTRAIN_H

#include "GoodsTrain.h"

/**
 * @class LargeGoodsTrain
 * @brief Klasa reprezentująca duży pociąg towarowy, dziedzicząca po GoodsTrain.
 *
 * Umożliwia stworzenie pociągu z określoną liczbą miejsc oraz parametrami ładunku.
 * Zawiera nadpisaną metodę do pobierania informacji tekstowej o pociągu.
 */
class LargeGoodsTrain : public GoodsTrain {
public:
    /**
     * @brief Konstruktor parametryczny klasy LargeGoodsTrain.
     *
     * @param name Nazwa pociągu.
     * @param trainNumber Numer identyfikacyjny pociągu.
     * @param seats Liczba miejsc w pociągu (domyślnie 0 dla towarowych).
     * @param courrentLoadKg Aktualne obciążenie pociągu w kilogramach.
     * @param maxLoadKg Maksymalne dozwolone obciążenie w kilogramach.
     */
    LargeGoodsTrain(const std::string& name, int trainNumber, int seats, double currentLoadKg, double maxLoadKg);

    /**
     * @brief Wirtualny destruktor klasy LargeGoodsTrain.
     *
     * Klasa jest abstrakcyjna — destruktor również jest czysto wirtualny.
     */
    virtual ~LargeGoodsTrain();

    /**
     * @brief Zwraca informacje tekstowe o pociągu.
     *
     * Nadpisuje metodę z klasy bazowej GoodsTrain.
     *
     * @return Ciąg znaków zawierający informacje o pociągu.
     */
    std::string getInfo() const override;
};

#endif // LARGEGOODSTRAIN_H

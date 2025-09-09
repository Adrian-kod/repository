/**
 * @file StudentDiscount.h
 * @brief Definicja klasy StudentDiscount reprezentującej rabat dla studentów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#ifndef STUDENTDISCOUNT_H
#define STUDENTDISCOUNT_H

#include "DiscountRate.h"

/**
 * @class StudentDiscount
 * @brief Klasa reprezentująca rabat dla studentów, dziedzicząca po DiscountRate.
 *
 * Klasa StudentDiscount implementuje specyficzną stawkę rabatu dla klientów będących studentami.
 * Dziedziczy po klasie bazowej DiscountRate i dostarcza własną implementację metod wirtualnych.
 */
class StudentDiscount : public DiscountRate {
public:
    /**
     * @brief Konstruktor domyślny klasy StudentDiscount.
     */
    StudentDiscount();

    /**
     * @brief Czysto wirtualny destruktor klasy StudentDiscount.
     */
    virtual ~StudentDiscount();

    /**
     * @brief Stosuje rabat dla studentów do ceny bazowej.
     * @param basePrice Cena bazowa, do której stosowany jest rabat.
     * @return Cena po zastosowaniu rabatu jako double.
     */
    double applyDiscount(double basePrice) override;

    /**
     * @brief Pobiera stawkę rabatu dla studentów.
     * @return Wartość stawki rabatu jako double.
     */
    double getDiscountRate() const override;
};

#endif //STUDENTDISCOUNT_H

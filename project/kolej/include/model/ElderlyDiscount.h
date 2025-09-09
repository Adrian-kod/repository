/**
 * @file ElderlyDiscount.h
 * @brief Definicja klasy ElderlyDiscount reprezentującej rabat dla seniorów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#ifndef ELDERLYDISCOUNT_H
#define ELDERLYDISCOUNT_H

#include "DiscountRate.h"

/**
 * @class ElderlyDiscount
 * @brief Klasa reprezentująca rabat dla seniorów, dziedzicząca po DiscountRate.
 *
 * Klasa ElderlyDiscount implementuje specyficzną stawkę rabatu dla klientów seniorów.
 * Dziedziczy po klasie bazowej DiscountRate i dostarcza własną implementację metod wirtualnych.
 */
class ElderlyDiscount : public DiscountRate {
public:
    /**
     * @brief Konstruktor domyślny klasy ElderlyDiscount.
     */
    ElderlyDiscount();

    /**
     * @brief Czysto wirtualny destruktor klasy ElderlyDiscount.
     */
    virtual ~ElderlyDiscount() = 0;

    /**
     * @brief Stosuje rabat dla seniorów do ceny bazowej.
     * @param basePrice Cena bazowa, do której stosowany jest rabat.
     * @return Cena po zastosowaniu rabatu jako double.
     */
    double applyDiscount(double basePrice) override;

    /**
     * @brief Pobiera stawkę rabatu dla seniorów.
     * @return Wartość stawki rabatu jako double.
     */
    double getDiscountRate() const override;
};

#endif //ELDERLYDISCOUNT_H

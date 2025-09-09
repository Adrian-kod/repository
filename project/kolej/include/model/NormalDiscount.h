/**
 * @file NormalDiscount.h
 * @brief Definicja klasy NormalDiscount reprezentującej standardowy rabat.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#ifndef NORMALDISCOUNT_H
#define NORMALDISCOUNT_H

#include "DiscountRate.h"

/**
 * @class NormalDiscount
 * @brief Klasa reprezentująca standardowy rabat, dziedzicząca po DiscountRate.
 *
 * Klasa NormalDiscount implementuje standardową stawkę rabatu dla klientów.
 * Dziedziczy po klasie bazowej DiscountRate i dostarcza własną implementację metod wirtualnych.
 */
class NormalDiscount : public DiscountRate {
public:
    /**
     * @brief Konstruktor domyślny klasy NormalDiscount.
     */
    NormalDiscount();

    /**
     * @brief Czysto wirtualny destruktor klasy NormalDiscount.
     */
    virtual ~NormalDiscount() = 0;

    /**
     * @brief Stosuje standardowy rabat do ceny bazowej.
     * @param basePrice Cena bazowa, do której stosowany jest rabat.
     * @return Cena po zastosowaniu rabatu jako double.
     */
    double applyDiscount(double basePrice) override;

    /**
     * @brief Pobiera stawkę standardowego rabatu.
     * @return Wartość stawki rabatu jako double.
     */
    double getDiscountRate() const override;
};

#endif //NORMALDISCOUNT_H

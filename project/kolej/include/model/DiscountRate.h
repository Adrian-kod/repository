/**
 * @file DiscountRate.h
 * @brief Definicja klasy DiscountRate reprezentującej stawkę rabatu.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 09.06.2025
 */

#ifndef DISCOUNTRATE_H
#define DISCOUNTRATE_H

#include "../typedefs.h"
#include "Client.h"

/**
 * @class DiscountRate
 * @brief Klasa bazowa reprezentująca stawkę rabatu dla klienta.
 *
 * Klasa DiscountRate przechowuje informacje o stawce rabatu i umożliwia jej zastosowanie
 * do ceny bazowej. Jest to klasa abstrakcyjna.
 */
class DiscountRate {
private:
    double discountRate; ///< Stawka rabatu.

protected:
    /**
     * @brief Pobiera stawkę rabatu.
     * @return Wartość stawki rabatu jako double.
     */
    double getRate() const;

public:
    /**
     * @brief Konstruktor klasy DiscountRate.
     * @param rate Wartość stawki rabatu.
     */
    DiscountRate(double rate);

    /**
     * @brief Wirtualny destruktor klasy DiscountRate.
     */
    virtual ~DiscountRate() = default;

    /**
     * @brief Pobiera stawkę rabatu.
     * @return Wartość stawki rabatu jako double.
     */
    virtual double getDiscountRate() const = 0;

    /**
     * @brief Stosuje rabat do ceny bazowej.
     * @param basePrice Cena bazowa, do której stosowany jest rabat.
     * @return Cena po zastosowaniu rabatu jako double.
     */
    virtual double applyDiscount(double basePrice) = 0;
};

#endif //DISCOUNTRATE_H

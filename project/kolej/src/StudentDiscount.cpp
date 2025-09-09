/**
 * @file StudentDiscount.cpp
 * @brief Implementacja klasy StudentDiscount reprezentującej rabat dla studentów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#include "../include/model/StudentDiscount.h"

/**
 * @brief Konstruktor domyślny klasy StudentDiscount.
 *
 * Ustawia stawkę rabatu na 50% (0.5) poprzez wywołanie konstruktora klasy bazowej DiscountRate.
 */
StudentDiscount::StudentDiscount() : DiscountRate(0.5) {}

/**
 * @brief Destruktor klasy StudentDiscount.
 */
StudentDiscount::~StudentDiscount() {}

/**
 * @brief Stosuje rabat dla studentów do ceny bazowej.
 * @param basePrice Cena bazowa, do której stosowany jest rabat.
 * @return Cena po zastosowaniu rabatu jako double.
 */
double StudentDiscount::applyDiscount(double basePrice) {
    return basePrice * (1.0 - getRate());
}

/**
 * @brief Pobiera stawkę rabatu dla studentów.
 * @return Wartość stawki rabatu jako double.
 */
double StudentDiscount::getDiscountRate() const {
    return getRate();
}


/**
 * @file ElderlyDiscount.cpp
 * @brief Implementacja klasy ElderlyDiscount reprezentującej rabat dla seniorów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#include "../include/model/ElderlyDiscount.h"

/**
 * @brief Konstruktor domyślny klasy ElderlyDiscount.
 *
 * Ustawia stawkę rabatu na 40% (0.4) poprzez wywołanie konstruktora klasy bazowej DiscountRate.
 */
ElderlyDiscount::ElderlyDiscount() : DiscountRate(0.4) {}

/**
 * @brief Destruktor klasy ElderlyDiscount.
 */
ElderlyDiscount::~ElderlyDiscount() {}

/**
 * @brief Stosuje rabat dla seniorów do ceny bazowej.
 * @param basePrice Cena bazowa, do której stosowany jest rabat.
 * @return Cena po zastosowaniu rabatu jako double.
 */
double ElderlyDiscount::applyDiscount(double basePrice) {
    return basePrice * (1.0 - getRate());
}

/**
 * @brief Pobiera stawkę rabatu dla seniorów.
 * @return Wartość stawki rabatu jako double.
 */
double ElderlyDiscount::getDiscountRate() const {
    return getRate();
}
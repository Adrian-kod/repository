/**
 * @file NormalDiscount.cpp
 * @brief Implementacja klasy NormalDiscount reprezentującej standardowy rabat.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#include "../include/model/NormalDiscount.h"

/**
 * @brief Konstruktor domyślny klasy NormalDiscount.
 *
 * Ustawia stawkę rabatu na 0% (0.0) poprzez wywołanie konstruktora klasy bazowej DiscountRate.
 */
NormalDiscount::NormalDiscount() : DiscountRate(0.0) {}

/**
 * @brief Destruktor klasy NormalDiscount.
 */
NormalDiscount::~NormalDiscount() {}

/**
 * @brief Stosuje standardowy rabat do ceny bazowej.
 * @param basePrice Cena bazowa, do której stosowany jest rabat.
 * @return Cena bazowa bez zmian, jako double.
 */
double NormalDiscount::applyDiscount(double basePrice) {
    return basePrice;
}

/**
 * @brief Pobiera stawkę standardowego rabatu.
 * @return Wartość stawki rabatu jako double.
 */
double NormalDiscount::getDiscountRate() const {
    return getRate();
}

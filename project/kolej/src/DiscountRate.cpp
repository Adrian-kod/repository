/**
 * @file DiscountRate.cpp
 * @brief Implementacja klasy DiscountRate reprezentującej stawkę rabatu.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 09.06.2025
 */

#include "../include/model/DiscountRate.h"

/**
 * @brief Konstruktor klasy DiscountRate.
 *
 * Inicjalizuje obiekt klasy DiscountRate z podaną wartością stawki rabatu.
 *
 * @param rate Wartość stawki rabatu.
 */
DiscountRate::DiscountRate(double rate) : discountRate(rate) {}

/**
 * @brief Pobiera stawkę rabatu.
 *
 * Zwraca wartość stawki rabatu przechowywaną w obiekcie.
 *
 * @return Wartość stawki rabatu jako double.
 */
double DiscountRate::getRate() const
{
    return discountRate;
}



//
// Created by atame on 09.06.2025.
//

#include "../include/model/WorkerDiscount.h"

WorkerDiscount::WorkerDiscount() : DiscountRate(0.99) {}

WorkerDiscount::~WorkerDiscount() {}

double WorkerDiscount::applyDiscount(double basePrice)
{
    return basePrice * (1.0 - getRate());
}


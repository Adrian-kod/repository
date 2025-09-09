//
// Created by atame on 09.06.2025.
//

#ifndef WORKERDISCOUNT_H
#define WORKERDISCOUNT_H

#include "DiscountRate.h"

class WorkerDiscount : public DiscountRate{
public:
    WorkerDiscount();
    virtual ~WorkerDiscount() = 0;

    double applyDiscount(double basePrice) override;
};

#endif //WORKERDISCOUNT_H

//
// Created by atame on 09.06.2025.
//

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <memory>

class Ticket;
class Schedule;
class Client;
class Train;
class Route;
class DiscountRate;

typedef std::shared_ptr<Ticket> TicketPtr;
typedef std::shared_ptr<Schedule> SchedulePtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Train> TrainPtr;
typedef std::shared_ptr<Route> RoutePtr;
typedef std::shared_ptr<DiscountRate> DiscountRatePtr;


#endif //TYPEDEFS_H


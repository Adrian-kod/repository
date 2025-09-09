/**
 * @file TicketSystem.h
 * @brief Deklaracja klasy TicketSystem, reprezentującej system zarządzania biletami, klientami i rozkładami.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 13.06.2025
 */

#ifndef TICKETSYSTEM_H
#define TICKETSYSTEM_H

#include "../typedefs.h"
#include <vector>
#include <memory>

/**
 * @class TicketSystem
 * @brief Klasa zarządzająca kolekcjami biletów, klientów i rozkładów jazdy.
 *
 * Przechowuje i zarządza wektorami wskaźników na obiekty Ticket, Client oraz Schedule.
 */
class TicketSystem {
private:
    /**
     * @brief Kolekcja wskaźników na bilety.
     */
    std::vector<TicketPtr> tickets;

    /**
     * @brief Kolekcja wskaźników na klientów.
     */
    std::vector<ClientPtr> clients;

    /**
     * @brief Kolekcja wskaźników na rozkłady jazdy.
     */
    std::vector<SchedulePtr> schedules;

public:
    // Można dodać tutaj deklaracje metod zarządzających systemem (opcjonalnie).
};

#endif // TICKETSYSTEM_H


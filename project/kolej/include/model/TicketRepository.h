/**
 * @file TicketRepository.h
 * @brief Deklaracja klasy TicketRepository, zarządzającej kolekcją biletów.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 13.06.2025
 */

#ifndef TICKETREPOSITORY_H
#define TICKETREPOSITORY_H

#include "Ticket.h"
#include <vector>
#include <memory>

/**
 * @class TicketRepository
 * @brief Klasa odpowiedzialna za dodawanie i usuwanie biletów z kolekcji.
 */
class TicketRepository {
public:
    /**
     * @brief Dodaje bilet do wektora biletów.
     *
     * @param ticket Referencja do obiektu Ticket do dodania.
     * @param tickets Referencja do wektora wskaźników TicketPtr, gdzie bilet ma być dodany.
     */
    void addTicket(const Ticket& ticket, std::vector<TicketPtr>& tickets);

    /**
     * @brief Usuwa bilet z wektora biletów.
     *
     * @param ticket Referencja do obiektu Ticket do usunięcia.
     * @param tickets Referencja do wektora wskaźników TicketPtr, z którego bilet ma być usunięty.
     */
    void removeTicket(const Ticket& ticket, std::vector<TicketPtr>& tickets);
};

#endif // TICKETREPOSITORY_H

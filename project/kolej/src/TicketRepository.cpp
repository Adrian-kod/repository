/**
 * @file TicketRepository.cpp
 * @brief Implementacja klasy TicketRepository, zarządzającej kolekcją biletów.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 14.06.2025
 */

#include "../include/model/TicketRepository.h"
#include <algorithm>
#include "../include/model/Schedule.h"
#include "../include/model/typedefs.h"

/**
 * @brief Dodaje bilet do kolekcji biletów.
 * @param ticket Referencja do obiektu biletu do dodania.
 * @param tickets Referencja do wektora wskaźników na bilety, do którego zostanie dodany nowy bilet.
 */
void TicketRepository::addTicket(const Ticket& ticket, std::vector<TicketPtr>& tickets)
{
    tickets.push_back(std::make_shared<Ticket>(ticket));
}

/**
 * @brief Usuwa bilet z kolekcji biletów na podstawie identyfikatora biletu.
 * @param ticket Referencja do obiektu biletu, który ma zostać usunięty.
 * @param tickets Referencja do wektora wskaźników na bilety, z którego zostanie usunięty bilet.
 */
void TicketRepository::removeTicket(const Ticket& ticket, std::vector<TicketPtr>& tickets)
{
    tickets.erase(
        std::remove_if(tickets.begin(), tickets.end(),
            [&ticket](const TicketPtr& t) {
                return t->getTicketId() == ticket.getTicketId();
            }),
        tickets.end()
    );
}

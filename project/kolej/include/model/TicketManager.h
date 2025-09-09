/**
 * @file TicketManager.h
 * @brief Deklaracja klasy TicketManager, zarządzającej zbiorami biletów.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 13.06.2025
 */

#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include "../typedefs.h"
#include <vector>
#include <memory>

/**
 * @class TicketManager
 * @brief Klasa zarządzająca kolekcją biletów.
 *
 * Umożliwia tworzenie i liczenie biletów.
 */
class TicketManager {
private:
    /**
     * @brief Kontener przechowujący wskaźniki do obiektów Ticket.
     */
    std::vector<TicketPtr> tickets;

public:
    /**
     * @brief Konstruktor domyślny klasy TicketManager.
     */
    TicketManager();

    /**
     * @brief Destruktor klasy TicketManager.
     */
    ~TicketManager();

    /**
     * @brief Tworzy bilety na podstawie podanych danych.
     *
     * @param tickets Wejściowy wektor wskaźników do biletów do utworzenia.
     * @param clients Wejściowy wektor wskaźników do klientów (parametr prawdopodobnie do uzupełnienia).
     * @return True jeśli utworzenie zakończyło się sukcesem, false w przeciwnym wypadku.
     */
    bool createTicket(std::vector<TicketPtr> tickets, std::vector<TicketPtr> clients);

    /**
     * @brief Zwraca liczbę aktualnie przechowywanych biletów.
     * @return Ilość biletów.
     */
    int countTickets() const;

};

#endif // TICKETMANAGER_H

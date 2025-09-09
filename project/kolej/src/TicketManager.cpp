/**
 * @file TicketManager.cpp
 * @brief Implementacja klasy TicketManager, zarządzającej zbiorami biletów.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 14.06.2025
 */

#include "../include/typedefs.h"
#include "../include/model/TicketManager.h"

/**
 * @brief Konstruktor domyślny klasy TicketManager.
 */
TicketManager::TicketManager() : tickets() {}

/**
 * @brief Destruktor klasy TicketManager.
 */
TicketManager::~TicketManager() {}

/**
 * @brief Tworzy bilety i dodaje je do wewnętrznej kolekcji.
 *
 * Sprawdza, czy podane wektory biletów i klientów nie są puste,
 * a następnie dodaje bilety do zarządzanej listy.
 *
 * @param tickets Wektor wskaźników do obiektów Ticket do dodania.
 * @param clients Wektor wskaźników do obiektów reprezentujących klientów (niewykorzystany w implementacji).
 * @return true, jeśli bilety zostały dodane, false jeśli któryś z wektorów był pusty.
 */
bool TicketManager::createTicket(std::vector<TicketPtr> tickets, std::vector<TicketPtr> clients)
{
    if (tickets.empty() || clients.empty()) {
        return false;
    }
    this->tickets.insert(this->tickets.end(), tickets.begin(), tickets.end());
    return true;
}

/**
 * @brief Zwraca liczbę biletów aktualnie zarządzanych.
 * @return Liczba biletów.
 */
int TicketManager::countTickets() const
{
    return static_cast<int>(tickets.size());
}

/**
 * @file TicketSystem.cpp
 * @brief Implementacja klasy TicketSystem zarządzającej kolekcjami biletów, klientów oraz rozkładów jazdy.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 14.06.2025
 */

#include "../include/model/TicketSystem.h"
#include "../include/model/TicketManager.h"

TicketSystem::TicketSystem() : tickets(), clients(), schedules() {}

/**
 * @brief Wirtualny destruktor klasy TicketSystem.
 */
TicketSystem::~TicketSystem() {}

std::vector<TicketPtr> TicketSystem::getTickets() const
{
    return tickets;
}

std::vector<ClientPtr> TicketSystem::getClients() const
{
    return clients;
}

std::vector<SchedulePtr> TicketSystem::getSchedules() const
{
    return schedules;
}

/**
 * @brief Dodaje nowy bilet do systemu.
 * @param ticket Wskaźnik na obiekt biletu do dodania.
 */
void TicketSystem::addTicket(const TicketPtr& ticket)
{
    tickets.push_back(ticket);
}

/**
 * @brief Dodaje nowego klienta do systemu.
 * @param client Wskaźnik na obiekt klienta do dodania.
 */
void TicketSystem::addClient(const ClientPtr& client)
{
    clients.push_back(client);
}

/**
 * @brief Dodaje nowy rozkład jazdy do systemu.
 * @param schedule Wskaźnik na obiekt rozkładu jazdy do dodania.
 */
void TicketSystem::addSchedule(const SchedulePtr& schedule)
{
    schedules.push_back(schedule);
}

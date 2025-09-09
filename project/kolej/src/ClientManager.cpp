/**
 * @file ClientManager.cpp
 * @brief Implementacja klasy ClientManager zarządzającej klientami w systemie.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 09.06.2025
 */

#include "../include/typedefs.h"
#include "../include/model/ClientManager.h"
#include "../include/model/Client.h"

/**
 * @brief Konstruktor klasy ClientManager.
 *
 * Inicjalizuje pustą listę klientów.
 */
ClientManager::ClientManager() {}

/**
 * @brief Destruktor klasy ClientManager.
 *
 * Zwalnia zasoby związane z obiektem klasy ClientManager.
 */
ClientManager::~ClientManager() {}

/**
 * @brief Pobiera listę wszystkich klientów.
 *
 * Zwraca przekazany wektor klientów bez żadnych modyfikacji.
 *
 * @param clients Wektor klientów do zwrócenia.
 * @return Wektor wskaźników na obiekty klasy Client.
 */
std::vector<ClientPtr> ClientManager::getAllClients(std::vector<ClientPtr> clients)
{
    return clients;
}

/**
 * @brief Sprawdza, czy dany klient istnieje w podanym wektorze klientów.
 *
 * Porównuje imię, nazwisko i numer telefonu klienta z każdym klientem w wektorze.
 *
 * @param client Obiekt klasy Client do sprawdzenia.
 * @param clients Wektor klientów, w którym wykonywane jest wyszukiwanie.
 * @return true, jeśli klient istnieje w wektorze, false w przeciwnym razie.
 */
bool ClientManager::checkClient(const Client& client, std::vector<ClientPtr> clients)
{
    for(const auto& c : clients)
    {
        if (c->getFirstName() == client.getFirstName() &&
            c->getLastName() == client.getLastName() &&
            c->getPhoneNumber() == client.getPhoneNumber())
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Zlicza liczbę klientów w systemie.
 *
 * Zwraca rozmiar wektora przechowującego klientów.
 *
 * @return Liczba klientów w wektorze jako int.
 */
int ClientManager::countClients() const
{
    return clients.size();
}




/**
 * @file ClientRepository.cpp
 * @brief Implementacja klasy ClientRepository zarządzającej repozytorium klientów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 09.06.2025
 */

#include "../include/model/ClientRepository.h"
#include "../include/model/Client.h"
#include "../include/typedefs.h"
#include "../include/model/ClientManager.h"
#include <vector>
#include <algorithm>
#include <memory>

/**
 * @brief Dodaje klienta do wektora klientów.
 *
 * Tworzy kopię podanego klienta za pomocą metody copy() i dodaje ją do wektora klientów.
 *
 * @param client Obiekt klasy Client do dodania.
 * @param clients Wektor klientów, do którego dodawany jest klient.
 */
void ClientRepository::addClient(const Client& client, std::vector<ClientPtr>& clients) {
    clients.push_back(client.copy());
}

/**
 * @brief Usuwa klienta z wektora klientów.
 *
 * Usuwa wszystkie wystąpienia klienta, którego imię, nazwisko i numer telefonu zgadzają się
 * z podanym obiektem klienta, z wektora klientów.
 *
 * @param client Obiekt klasy Client do usunięcia.
 * @param clients Wektor klientów, z którego usuwany jest klient.
 */
void ClientRepository::removeClient(const Client& client, std::vector<ClientPtr>& clients) {
    auto it = std::remove_if(clients.begin(), clients.end(),
        [&client](const ClientPtr& c) {
            return c->getFirstName() == client.getFirstName() &&
                   c->getLastName() == client.getLastName() &&
                   c->getPhoneNumber() == client.getPhoneNumber();
        }
    );

    clients.erase(it, clients.end());
}
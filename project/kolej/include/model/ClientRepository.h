/**
 * @file ClientRepository.h
 * @brief Definicja klasy ClientRepository zarządzającej repozytorium klientów.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 09.06.2025
 */

#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H

#include "Client.h"
#include <vector>
#include <memory>

/**
 * @class ClientRepository
 * @brief Klasa odpowiedzialna za zarządzanie repozytorium klientów.
 *
 * Klasa ClientRepository umożliwia dodawanie i usuwanie klientów z podanego wektora klientów.
 */
class ClientRepository {
public:
    /**
     * @brief Dodaje klienta do wektora klientów.
     *
     * @param client Obiekt klasy Client do dodania.
     * @param clients Wektor klientów, do którego dodawany jest klient.
     */
    void addClient(const Client& client, std::vector<ClientPtr>& clients);

    /**
     * @brief Usuwa klienta z wektora klientów.
     *
     * @param client Obiekt klasy Client do usunięcia.
     * @param clients Wektor klientów, z którego usuwany jest klient.
     */
    void removeClient(const Client& client, std::vector<ClientPtr>& clients);
};

#endif //CLIENTREPOSITORY_H

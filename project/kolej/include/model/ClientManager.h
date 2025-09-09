/**
 * @file ClientManager.h
 * @brief Definicja klasy ClientManager zarządzającej klientami w systemie.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 09.06.2025
 */

#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "../typedefs.h"
#include <vector>
#include <memory>

/**
 * @class ClientManager
 * @brief Klasa zarządzająca zbiorem klientów w systemie.
 *
 * Klasa ClientManager przechowuje listę klientów i umożliwia wykonywanie operacji
 * takich jak pobieranie wszystkich klientów, sprawdzanie istnienia klienta
 * oraz zliczanie klientów.
 */
class ClientManager {
private:
    std::vector<ClientPtr> clients; ///< Wektor wskaźników na obiekty klasy Client.

public:
    /**
     * @brief Konstruktor klasy ClientManager.
     *
     * Inicjalizuje pustą listę klientów.
     */
    ClientManager();

    /**
     * @brief Destruktor klasy ClientManager.
     *
     * Zwalnia zasoby związane z obiektem klasy ClientManager.
     */
    ~ClientManager();

    /**
     * @brief Pobiera listę wszystkich klientów.
     *
     * Zwraca wektor zawierający wskaźniki na wszystkich klientów.
     *
     * @param clients Wektor klientów do przetworzenia.
     * @return Wektor wskaźników na obiekty klasy Client.
     */
    std::vector<ClientPtr> getAllClients(std::vector<ClientPtr> clients);

    /**
     * @brief Sprawdza, czy dany klient istnieje w systemie.
     *
     * @param client Obiekt klasy Client do sprawdzenia.
     * @param clients Wektor klientów, w którym wykonywane jest wyszukiwanie.
     * @return true, jeśli klient istnieje w wektorze, false w przeciwnym razie.
     */
    bool checkClient(const Client& client, std::vector<ClientPtr> clients);

    /**
     * @brief Zlicza liczbę klientów w systemie.
     *
     * @return Liczba klientów w wektorze jako int.
     */
    int countClients() const;
};

#endif //CLIENTMANAGER_H

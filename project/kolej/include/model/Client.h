/**
 * @file Client.h
 * @brief Definicja klasy Client reprezentującej klienta w systemie.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 08.06.2025
 */

#ifndef CLIENT_H
#define CLIENT_H

#include "../typedefs.h"
#include <string>
#include <vector>
#include <memory>
#pragma once

/**
 * @class Client
 * @brief Klasa bazowa reprezentująca klienta w systemie.
 *
 * Klasa Client przechowuje podstawowe informacje o kliencie, takie jak imię, nazwisko,
 * numer telefonu, stan portfela oraz listę biletów. Jest to klasa abstrakcyjna.
 */
class Client {
private:
    std::string firstName; ///< Imię klienta.
    std::string lastName;  ///< Nazwisko klienta.
    int phoneNumber;       ///< Numer telefonu klienta.
    std::string tickets;   ///< Informacje o biletach klienta.
    double wallet;         ///< Stan portfela klienta.
    std::vector<ClientPtr> clients; ///< Wektor wskaźników na innych klientów.

public:
    /**
     * @brief Konstruktor klasy Client.
     * @param firstName Imię klienta.
     * @param lastName Nazwisko klienta.
     * @param phoneNumber Numer telefonu klienta.
     * @param wallet Początkowy stan portfela klienta.
     */
    Client(const std::string& firstName, const std::string& lastName, int phoneNumber, double wallet);

    /**
     * @brief Wirtualny destruktor klasy Client.
     */
    virtual ~Client();

    /**
     * @brief Wirtualna metoda tworząca kopię obiektu.
     * @return Wskaźnik na skopiowany obiekt typu Client.
     */
    virtual ClientPtr copy() const;

    /**
     * @brief Pobiera imię klienta.
     * @return Imię klienta jako std::string.
     */
    std::string getFirstName() const;

    /**
     * @brief Pobiera nazwisko klienta.
     * @return Nazwisko klienta jako std::string.
     */
    std::string getLastName() const;

    /**
     * @brief Pobiera numer telefonu klienta.
     * @return Numer telefonu klienta jako int.
     */
    int getPhoneNumber() const;

    /**
     * @brief Pobiera stan portfela klienta.
     * @return Stan portfela klienta jako double.
     */
    double getWallet() const;

    /**
     * @brief Pobiera informacje o kliencie.
     * @return Informacje o kliencie jako std::string.
     */
    std::string getInfo() const;

    /**
     * @brief Ustawia imię klienta.
     * @param firstName Nowe imię klienta.
     */
    void setFirstName(const std::string& firstName);

    /**
     * @brief Ustawia nazwisko klienta.
     * @param lastName Nowe nazwisko klienta.
     */
    void setLastName(const std::string& lastName);

    /**
     * @brief Ustawia numer telefonu klienta.
     * @param phoneNumber Nowy numer telefonu klienta.
     */
    void setPhoneNumber(int phoneNumber);

    /**
     * @brief Ustawia stan portfela klienta.
     * @param wallet Nowy stan portfela klienta.
     */
    void setWallet(double wallet);
};


#endif //CLIENT_H
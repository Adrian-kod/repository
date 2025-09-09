/**
 * @file Client.cpp
 * @brief Implementacja klasy Client reprezentującej klienta w systemie.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 08.06.2025
 */

#include "../include/model/Client.h"

/**
 * @brief Konstruktor klasy Client.
 *
 * Inicjalizuje obiekt klasy Client z podanymi wartościami dla imienia, nazwiska,
 * numeru telefonu oraz stanu portfela.
 *
 * @param firstName Imię klienta.
 * @param lastName Nazwisko klienta.
 * @param phoneNumber Numer telefonu klienta.
 * @param wallet Początkowy stan portfela klienta.
 */
Client::Client(const std::string& firstName, const std::string& lastName, int phoneNumber, double wallet)
    : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), wallet(wallet) {}

/**
 * @brief Wirtualny destruktor klasy Client.
 *
 * Zwalnia zasoby związane z obiektem klasy Client.
 */
Client::~Client() {}

/**
 * @brief Pobiera imię klienta.
 * @return Imię klienta jako std::string.
 */
std::string Client::getFirstName() const
{
    return firstName;
}

/**
 * @brief Pobiera nazwisko klienta.
 * @return Nazwisko klienta jako std::string.
 */
std::string Client::getLastName() const
{
    return lastName;
}

/**
 * @brief Pobiera numer telefonu klienta.
 * @return Numer telefonu klienta jako int.
 */
int Client::getPhoneNumber() const
{
    return phoneNumber;
}

/**
 * @brief Pobiera stan portfela klienta.
 * @return Stan portfela klienta jako double.
 */
double Client::getWallet() const
{
    return wallet;
}

/**
 * @brief Pobiera informacje o kliencie.
 *
 * Zwraca sformatowany ciąg znaków zawierający informacje o kliencie,
 * takie jak imię, nazwisko, numer telefonu i stan portfela.
 *
 * @return Informacje o kliencie jako std::string.
 */
std::string Client::getInfo() const
{
    return "Klient:\n--> Imię: " + firstName +
           "\n--> Nazwisko: " + lastName +
           "\n--> Numer telefonu: " + std::to_string(phoneNumber) +
           "\n--> Portfel systemowy: " + std::to_string(wallet);
}

/**
 * @brief Ustawia imię klienta.
 * @param firstName Nowe imię klienta.
 */
void Client::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

/**
 * @brief Ustawia nazwisko klienta.
 * @param lastName Nowe nazwisko klienta.
 */
void Client::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

/**
 * @brief Ustawia numer telefonu klienta.
 * @param phoneNumber Nowy numer telefonu klienta.
 */
void Client::setPhoneNumber(int phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

/**
 * @brief Ustawia stan portfela klienta.
 * @param wallet Nowy stan portfela klienta.
 */
void Client::setWallet(double wallet)
{
    this->wallet = wallet;
}

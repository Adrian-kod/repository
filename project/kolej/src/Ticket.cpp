/**
 * @file Ticket.cpp
 * @brief Implementacja klasy Ticket, reprezentującej bilet na przejazd pociągiem.
 * @authors Hanna Mikołajczyk, Adrian Tameczka
 * @date 14.06.2025
 */

#include "../include/typedefs.h"
#include "../include/model/Ticket.h"

/**
 * @brief Konstruktor klasy Ticket.
 *
 * Inicjalizuje obiekt biletu z podanym klientem, harmonogramem oraz zniżką.
 * Cena, ID i numer miejsca są ustawiane domyślnie na 0.
 *
 * @param client Referencja do obiektu klienta (nieużywany w implementacji, może służyć do rozszerzeń).
 * @param schedule Referencja do harmonogramu przejazdu.
 * @param discount Referencja do zniżki na bilet.
 */
Ticket::Ticket(const Client& client, const Schedule& schedule, const DiscountRate& discount)
    : schedule(new Schedule(schedule)), discount(new DiscountRate(discount)), price(0.0), ticketId(0), seatNumber(0) {}

/**
 * @brief Wirtualny destruktor klasy Ticket.
 *
 * Zwalnia dynamicznie zaalokowaną pamięć dla schedule i discount.
 */
Ticket::~Ticket() {
    delete schedule;
    delete discount;
}

/**
 * @brief Zwraca harmonogram przejazdu.
 * @return Wskaźnik na obiekt klasy Schedule.
 */
Schedule* Ticket::getSchedule() const {
    return schedule;
}

/**
 * @brief Zwraca wartość zniżki.
 * @return Wskaźnik na obiekt typu DiscountRate.
 */
DiscountRate* Ticket::getDiscount() const {
    return discount;
}

/**
 * @brief Zwraca cenę biletu.
 * @return Cena jako double.
 */
double Ticket::getPrice() const {
    return price;
}

/**
 * @brief Zwraca unikalny identyfikator biletu.
 * @return Identyfikator biletu.
 */
int Ticket::getTicketId() const {
    return ticketId;
}

/**
 * @brief Zwraca numer miejsca siedzącego.
 * @return Numer miejsca jako int.
 */
int Ticket::getSeatNumber() const {
    return seatNumber;
}

/**
 * @brief Zwraca tekstową informację o bilecie.
 * @return String zawierający ID biletu, numer miejsca oraz cenę.
 */
std::string Ticket::getInfo() const {
    return "Bilet:\n--> ID: " + std::to_string(ticketId) +
           "\n--> Miejsce: " + std::to_string(seatNumber) +
           "\n--> Cena: " + std::to_string(price);
}

/**
 * @brief Ustawia harmonogram przejazdu.
 * @param schedule Nowy harmonogram.
 */
void Ticket::setSchedule(const Schedule& schedule) {
    delete this->schedule;
    this->schedule = new Schedule(schedule);
}

/**
 * @brief Ustawia wartość zniżki.
 * @param discount Nowa zniżka.
 */
void Ticket::setDiscount(const DiscountRate& discount) {
    delete this->discount;
    this->discount = new DiscountRate(discount);
}

/**
 * @brief Ustawia cenę biletu.
 * @param price Nowa cena biletu.
 */
void Ticket::setPrice(double price) {
    this->price = price;
}

/**
 * @brief Ustawia unikalny identyfikator biletu.
 * @param ticketId Nowy identyfikator.
 */
void Ticket::setTicketId(int ticketId) {
    this->ticketId = ticketId;
}

/**
 * @brief Ustawia numer miejsca siedzącego.
 * @param seatNumber Nowy numer miejsca.
 */
void Ticket::setSeatNumber(int seatNumber) {
    this->seatNumber = seatNumber;
}

/**
 * @brief Oblicza cenę biletu uwzględniając zniżkę.
 *
 * Pobiera cenę bazową z harmonogramu i aplikuje zniżkę.
 *
 * @return Cena biletu po zastosowaniu zniżki.
 */
double Ticket::calculatePrice() const {
    double basePrice = schedule->getBasePrice(); // Używamy -> zamiast .
    return discount->applyDiscount(basePrice);   // Używamy -> zamiast .
}
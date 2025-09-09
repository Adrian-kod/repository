/**
 * @file Ticket.h
 * @brief Deklaracja klasy Ticket, reprezentującej bilet na przejazd pociągiem.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 13.06.2025
 */

#ifndef TICKET_H
#define TICKET_H

#include "../typedefs.h"
#include "Schedule.h"
#include <string>
#include <vector>

/**
 * @class Ticket
 * @brief Klasa reprezentująca bilet na przejazd.
 *
 * Zawiera informacje o harmonogramie, zniżce, cenie, numerze biletu oraz miejscu siedzącym.
 */
class Ticket
{
private:
    /**
     * @brief Wskaźnik na harmonogram przejazdu.
     */
    Schedule* schedule;

    /**
     * @brief Wskaźnik na stawkę zniżkową.
     */
    DiscountRate* discount;

    /**
     * @brief Cena biletu.
     */
    double price;

    /**
     * @brief Unikalny identyfikator biletu.
     */
    int ticketId;

    /**
     * @brief Numer miejsca siedzącego.
     */
    int seatNumber;

public:
    /**
     * @brief Konstruktor klasy Ticket.
     *
     * @param client Referencja do obiektu klienta kupującego bilet.
     * @param schedule Referencja do harmonogramu przejazdu.
     * @param discount Referencja do zniżki przypisanej do biletu.
     */
    Ticket(const Client& client, const Schedule& schedule, const DiscountRate& discount);

    /**
     * @brief Wirtualny destruktor klasy Ticket.
     */
    virtual ~Ticket();

    /**
     * @brief Zwraca harmonogram przejazdu.
     * @return Wskaźnik na obiekt klasy Schedule.
     */
    Schedule* getSchedule() const;

    /**
     * @brief Zwraca przypisaną zniżkę.
     * @return Wskaźnik na obiekt typu DiscountRate.
     */
    DiscountRate* getDiscount() const;

    /**
     * @brief Zwraca cenę biletu.
     * @return Cena jako double.
     */
    double getPrice() const;

    /**
     * @brief Zwraca unikalny identyfikator biletu.
     * @return Identyfikator biletu.
     */
    int getTicketId() const;

    /**
     * @brief Zwraca numer miejsca siedzącego.
     * @return Numer miejsca.
     */
    int getSeatNumber() const;

    /**
     * @brief Zwraca informacje o bilecie w formie tekstowej.
     * @return String z informacjami o bilecie.
     */
    virtual std::string getInfo() const;

    /**
     * @brief Ustawia harmonogram przejazdu.
     * @param schedule Nowy harmonogram.
     */
    void setSchedule(const Schedule& schedule);

    /**
     * @brief Ustawia zniżkę.
     * @param discount Nowa zniżka.
     */
    void setDiscount(const DiscountRate& discount);

    /**
     * @brief Ustawia cenę biletu.
     * @param price Nowa cena.
     */
    void setPrice(double price);

    /**
     * @brief Ustawia unikalny identyfikator biletu.
     * @param ticketId Nowy identyfikator.
     */
    void setTicketId(int ticketId);

    /**
     * @brief Ustawia numer miejsca siedzącego.
     * @param seatNumber Nowy numer miejsca.
     */
    void setSeatNumber(int seatNumber);

    /**
     * @brief Oblicza cenę biletu uwzględniając zniżkę.
     * @return Obliczona cena biletu.
     */
    virtual double calculatePrice() const;
};

#endif //TICKET_H

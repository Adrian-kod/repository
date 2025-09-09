/**
 * @file Route.h
 * @brief Deklaracja klasy Route, reprezentującej trasę kolejową między stacjami.
 * @authors Hanna Mikołajczyk, Adrian Tameczka
 * @date 09.06.2025
 */

#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <stdexcept>

/**
 * @class Route
 * @brief Klasa abstrakcyjna reprezentująca trasę kolejową.
 *
 * Zawiera informacje o stacjach początkowej i końcowej, czasie trwania trasy oraz liczbie stacji pośrednich.
 */
class Route {
private:
    /**
     * @brief Nazwa stacji początkowej.
     */
    std::string firstStation;

    /**
     * @brief Nazwa stacji końcowej.
     */
    std::string lastStation;

    /**
     * @brief Czas trwania trasy (w godzinach).
     */
    double duration;

    /**
     * @brief Liczba stacji na trasie (w formie tekstowej, np. "5 przystanków").
     */
    std::string numberOfStations;

public:
    /**
     * @brief Konstruktor klasy Route.
     *
     * @param first_station Nazwa stacji początkowej.
     * @param last_station Nazwa stacji końcowej.
     * @param duration Czas trwania trasy w godzinach.
     * @param number_of_stations Tekstowy opis liczby stacji (np. "3 stacje").
     */
    Route(const std::string& firstStation, const std::string& lastStation, double duration,
          const std::string& numberOfStations);

    /**
     * @brief Wirtualny destruktor czysto wirtualny (klasa abstrakcyjna).
     */
    virtual ~Route();

    /**
     * @brief Zwraca nazwę stacji początkowej.
     * @return Nazwa stacji początkowej.
     */
    std::string getFirstStation() const;

    /**
     * @brief Zwraca nazwę stacji końcowej.
     * @return Nazwa stacji końcowej.
     */
    std::string getLastStation() const;

    /**
     * @brief Zwraca czas trwania trasy.
     * @return Czas trwania w godzinach.
     */
    double getDuration() const;

    /**
     * @brief Zwraca tekstowy opis liczby stacji.
     * @return Liczba stacji jako string.
     */
    std::string getNumberOfStations() const;

    /**
     * @brief Ustawia stację początkową.
     * @param first_station Nowa nazwa stacji początkowej.
     */
    void setFirstStation(const std::string& firstStation);

    /**
     * @brief Ustawia stację końcową.
     * @param last_station Nowa nazwa stacji końcowej.
     */
    void setLastStation(const std::string& lastStation);

    /**
     * @brief Ustawia czas trwania trasy.
     * @param duration Nowy czas trwania w godzinach.
     */
    void setDuration(double duration);

    /**
     * @brief Ustawia tekstowy opis liczby stacji.
     * @param number_of_stations Tekstowy opis (np. "6 stacji").
     */
    void setNumberOfStations(const std::string& numberOfStations);
};

#endif // ROUTE_H

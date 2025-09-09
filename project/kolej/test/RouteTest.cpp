/**
 * @file RouteTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Route.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 15.06.2025
 */

#include <boost/test/unit_test.hpp>
#include "../include/model/Route.h"

/**
 * @brief Klasa testowa dziedzicząca po Route.
 *
 * Umożliwia testowanie funkcjonalności klasy Route poprzez udostępnienie
 * konstruktora i destruktora dla celów testowych.
 */
class TestRoute : public Route {
public:
    /**
     * @brief Konstruktor klasy TestRoute.
     * @param first Stacja początkowa trasy.
     * @param last Stacja końcowa trasy.
     * @param duration Czas trwania podróży w godzinach.
     * @param stations Liczba stacji na trasie jako string.
     */
    TestRoute(const std::string& first, const std::string& last, double duration, const std::string& stations)
            : Route(first, last, duration, stations) {}

    /**
     * @brief Destruktor klasy TestRoute.
     */
    ~TestRoute() override = default;
};

/**
 * @brief Pakiet testów dla klasy Route.
 *
 * Zawiera testy sprawdzające funkcjonalność tras kolejowych.
 */
BOOST_AUTO_TEST_SUITE(RouteTests)

/**
 * @brief Test konstruktora i getterów klasy Route.
 *
 * Sprawdza czy klasa Route poprawnie inicjalizuje się z podanymi parametrami
 * i czy metody pobierające dane zwracają prawidłowe wartości.
 */
BOOST_AUTO_TEST_CASE(RouteConstructorAndGettersTest) {
    TestRoute route("Warszawa", "Krakow", 2.5, "5");

    BOOST_CHECK_EQUAL(route.getFirstStation(), "Warszawa");
    BOOST_CHECK_EQUAL(route.getLastStation(), "Krakow");
    BOOST_CHECK_CLOSE(route.getDuration(), 2.5, 0.001);
    BOOST_CHECK_EQUAL(route.getNumberOfStations(), "5");
}

/**
 * @brief Test walidacji pustych nazw stacji.
 *
 * Sprawdza czy konstruktor klasy Route poprawnie rzuca wyjątek
 * std::invalid_argument dla pustych nazw stacji początkowej lub końcowej.
 */
BOOST_AUTO_TEST_CASE(RouteEmptyStationsTest) {
    BOOST_CHECK_THROW(
        TestRoute("Warszawa", "", 2.5, "5"),
        std::invalid_argument
    );

    BOOST_CHECK_THROW(
        TestRoute("", "Krakow", 2.5, "5"),
        std::invalid_argument
    );
}

/**
 * @brief Test walidacji nieprawidłowego czasu trwania.
 *
 * Sprawdza czy konstruktor klasy Route poprawnie rzuca wyjątek
 * std::invalid_argument dla ujemnych lub zerowych wartości czasu trwania.
 */
BOOST_AUTO_TEST_CASE(RouteInvalidDurationTest) {
    BOOST_CHECK_THROW(
        TestRoute("Warszawa", "Krakow", -1.0, "5"),
        std::invalid_argument
    );

    BOOST_CHECK_THROW(
        TestRoute("Warszawa", "Krakow", 0.0, "5"),
        std::invalid_argument
    );
}

/**
 * @brief Test walidacji nieprawidłowej liczby stacji.
 *
 * Sprawdza czy konstruktor klasy Route poprawnie rzuca wyjątek
 * std::invalid_argument dla pustych lub ujemnych wartości liczby stacji.
 */
BOOST_AUTO_TEST_CASE(RouteInvalidStationsNumberTest) {
    BOOST_CHECK_THROW(
        TestRoute("Warszawa", "Krakow", 2.5, ""),
        std::invalid_argument
    );

    BOOST_CHECK_THROW(
        TestRoute("Warszawa", "Krakow", 2.5, "-1"),
        std::invalid_argument
    );
}

/**
 * @brief Test setterów klasy Route.
 *
 * Sprawdza czy metody setDuration() i setNumberOfStations() poprawnie
 * ustawiają nowe wartości oraz rzucają wyjątki dla nieprawidłowych danych.
 */
BOOST_AUTO_TEST_CASE(RouteSettersTest) {
    TestRoute route("Warszawa", "Krakow", 2.5, "5");

    route.setDuration(3.0);
    BOOST_CHECK_CLOSE(route.getDuration(), 3.0, 0.001);

    route.setNumberOfStations("6");
    BOOST_CHECK_EQUAL(route.getNumberOfStations(), "6");

    BOOST_CHECK_THROW(route.setDuration(-1.0), std::invalid_argument);
    BOOST_CHECK_THROW(route.setNumberOfStations(""), std::invalid_argument);
}

/**
 * @brief Test walidacji identycznych stacji.
 *
 * Sprawdza czy konstruktor klasy Route poprawnie rzuca wyjątek
 * std::invalid_argument gdy stacja początkowa i końcowa są identyczne.
 */
BOOST_AUTO_TEST_CASE(RouteSameStationsTest) {
    BOOST_CHECK_THROW(
        TestRoute("Warszawa", "Warszawa", 2.5, "6"),
        std::invalid_argument
    );
}

BOOST_AUTO_TEST_SUITE_END()


/**
 * @file TrainTest.cpp
 * @brief Testy jednostkowe dla klasy Route, weryfikujące funkcjonalność tras kolejowych.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 15.06.2025
 */

#include <boost/test/unit_test.hpp>
#include "../include/model/Route.h"

/**
 * @brief Klasa testowa dziedzicząca po Route.
 *
 * Umożliwia testowanie klasy Route poprzez udostępnienie konstruktora
 * i destruktora dla celów testowych.
 */
class TestRoute : public Route {
public:
    /**
     * @brief Konstruktor klasy TestRoute.
     *
     * Inicjalizuje klasę bazową Route z podanymi parametrami trasy.
     *
     * @param first Nazwa pierwszej stacji.
     * @param last Nazwa ostatniej stacji.
     * @param duration Czas trwania podróży.
     * @param stations Liczba stacji na trasie.
     */
    TestRoute(const std::string& first, const std::string& last, double duration, const std::string& stations)
        : Route(first, last, duration, stations) {}

    /**
     * @brief Wirtualny destruktor klasy TestRoute.
     */
    ~TestRoute() override = default;
};

/**
 * @brief Zestaw testów jednostkowych dla klasy Route.
 */
BOOST_AUTO_TEST_SUITE(RouteTests)

/**
 * @brief Test konstruktora klasy Route.
 *
 * Weryfikuje poprawność inicjalizacji obiektu Route z poprawnymi danymi
 * oraz sprawdza czy wszystkie pola są ustawione zgodnie z oczekiwaniami.
 */
BOOST_AUTO_TEST_CASE(RouteConstructorTest) {
    TestRoute route("Warszawa", "Krakow", 2.5, "5");

    BOOST_CHECK_EQUAL(route.getFirstStation(), "Warszawa");
    BOOST_CHECK_EQUAL(route.getLastStation(), "Krakow");
    BOOST_CHECK_EQUAL(route.getDuration(), 2.5);
    BOOST_CHECK_EQUAL(route.getNumberOfStations(), "5");
}

/**
 * @brief Test walidacji pustych nazw stacji.
 *
 * Sprawdza czy konstruktor klasy Route poprawnie rzuca wyjątek
 * std::invalid_argument w przypadku podania pustych nazw stacji
 * (pierwszej lub ostatniej).
 */
BOOST_AUTO_TEST_CASE(RouteEmptyStationNamesTest) {
    BOOST_CHECK_THROW(TestRoute("", "Krakow", 2.5, "5"), std::invalid_argument);
    BOOST_CHECK_THROW(TestRoute("Warszawa", "", 2.5, "5"), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
/**
 * @file ScheduleTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Schedule.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 15.06.2025
 */

#include <boost/test/unit_test.hpp>
#include "../include/model/Schedule.h"
#include "../include/model/Route.h"
#include "../include/model/Train.h"
#include <memory>
#include <vector>

/**
 * @brief Klasa testowa dziedzicząca po Route.
 *
 * Umożliwia testowanie funkcjonalności klasy Route w kontekście testów Schedule.
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
 * @brief Klasa testowa dziedzicząca po Train.
 *
 * Implementuje abstrakcyjną metodę getInfo() dla celów testowych Schedule.
 */
class TestTrain : public Train {
public:
    /**
     * @brief Konstruktor klasy TestTrain.
     * @param name Nazwa pociągu.
     * @param number Numer pociągu.
     * @param seats Liczba miejsc w pociągu.
     */
    TestTrain(const std::string& name, int number, int seats)
        : Train(name, number, seats) {}

    /**
     * @brief Destruktor klasy TestTrain.
     */
    ~TestTrain() override = default;

    /**
     * @brief Pobiera informacje o pociągu testowym.
     * @return String zawierający nazwę i numer pociągu.
     */
    std::string getInfo() const override { return getName() + " " + std::to_string(getTrainNumber()); }
};

/**
 * @brief Klasa testowa dziedzicząca po Schedule.
 *
 * Umożliwia testowanie funkcjonalności klasy Schedule.
 */
class TestSchedule : public Schedule {
public:
    /**
     * @brief Konstruktor klasy TestSchedule.
     * @param day Dzień tygodnia dla rozkładu.
     * @param trains Wektor wskaźników do pociągów.
     * @param routes Wektor wskaźników do tras.
     * @param firstHour Godzina pierwszego odjazdu.
     * @param lastHour Godzina ostatniego odjazdu.
     * @param firstStation Pierwsza stacja w rozkładzie.
     * @param lastStation Ostatnia stacja w rozkładzie.
     */
	TestSchedule(const std::string& day,
				 const std::string& firstStation, const std::string& lastStation, std::vector<TrainPtr> trains, std::vector<RoutePtr> routes,
                 const std::string& firstHour, const std::string& lastHour)
        : Schedule(day, firstStation, lastStation, trains, routes, firstHour, lastHour) {}

    /**
     * @brief Destruktor klasy TestSchedule.
     */
    ~TestSchedule() override = default;
};

/**
 * @brief Pakiet testów dla klasy Schedule.
 *
 * Zawiera testy sprawdzające funkcjonalność rozkładów jazdy.
 */
BOOST_AUTO_TEST_SUITE(ScheduleTests)

/**
 * @brief Test konstruktora klasy Schedule.
 *
 * Sprawdza czy klasa Schedule poprawnie inicjalizuje się z podanymi parametrami
 * i czy metody pobierające dane zwracają prawidłowe wartości.
 */
BOOST_AUTO_TEST_CASE(ScheduleConstructorTest) {
    std::vector<TrainPtr> trains{std::make_shared<TestTrain>("Express", 1234, 100)};
    std::vector<RoutePtr> routes{std::make_shared<TestRoute>("Warszawa", "Krakow", 2.5, "5")};

    TestSchedule schedule("Poniedzialek", "Warszawa", "Krakow", trains, routes, "06:00", "22:00");

	BOOST_CHECK_EQUAL(schedule.getDay(), "Poniedzialek");
	BOOST_CHECK_EQUAL(schedule.getFirstStation(), "Warszawa");
	BOOST_CHECK_EQUAL(schedule.getLastStation(), "Krakow");
    BOOST_CHECK_EQUAL(schedule.getFirstHour(), "06:00");
    BOOST_CHECK_EQUAL(schedule.getLastHour(), "22:00");
}

/**
 * @brief Test setterów klasy Schedule.
 *
 * Sprawdza czy metody setFirstHour(), setLastHour() i setDay() poprawnie
 * ustawiają nowe wartości w rozkładzie jazdy.
 */
BOOST_AUTO_TEST_CASE(ScheduleSettersTest) {
	std::vector<TrainPtr> trains{std::make_shared<TestTrain>("Express", 1234, 100)};
	std::vector<RoutePtr> routes{std::make_shared<TestRoute>("Warszawa", "Krakow", 2.5, "5")};

	TestSchedule schedule("Poniedzialek", "Warszawa", "Krakow", trains, routes, "06:00", "22:00");

	std::string newFirstHour = "07:00";
	std::string newLastHour = "21:00";
	std::string newDay = "Wtorek";

	schedule.setFirstHour(newFirstHour);
	BOOST_CHECK_EQUAL(schedule.getFirstHour(), "07:00");

	schedule.setLastHour(newLastHour);
	BOOST_CHECK_EQUAL(schedule.getLastHour(), "21:00");

	schedule.setDay(newDay);
	BOOST_CHECK_EQUAL(schedule.getDay(), "Wtorek");
}

/**
 * @brief Test obsługi pociągów i tras w rozkładzie.
 *
 * Sprawdza czy klasa Schedule poprawnie przechowuje i zwraca kolekcje
 * pociągów i tras w rozkładzie jazdy.
 */
BOOST_AUTO_TEST_CASE(ScheduleTrainsAndRoutesTest) {
    std::vector<TrainPtr> trains{
        std::make_shared<TestTrain>("Express", 1234, 100),
        std::make_shared<TestTrain>("Lokalny", 5678, 50)
    };
    std::vector<RoutePtr> routes{
        std::make_shared<TestRoute>("Warszawa", "Krakow", 2.5, "5"),
        std::make_shared<TestRoute>("Krakow", "Gdansk", 4.0, "8")
    };

    TestSchedule schedule("Poniedzialek", "Warszawa", "Krakow", trains, routes, "06:00", "22:00");

    BOOST_CHECK_EQUAL(schedule.getTrains().size(), 2);
    BOOST_CHECK_EQUAL(schedule.getRoutes().size(), 2);
}

/**
 * @brief Test walidacji nieprawidłowego formatu czasu.
 *
 * Sprawdza czy konstruktor klasy Schedule poprawnie rzuca wyjątek
 * std::invalid_argument dla nieprawidłowych formatów godzin.
 */
BOOST_AUTO_TEST_CASE(ScheduleInvalidTimeFormatTest) {
    std::vector<TrainPtr> trains;
    std::vector<RoutePtr> routes;

    BOOST_CHECK_THROW(
        TestSchedule schedule("Poniedzialek", "Warszawa", "Krakow", trains, routes, "25:00", "22:00"),
        std::invalid_argument
    );

    BOOST_CHECK_THROW(
        TestSchedule schedule("Poniedzialek", "Warszawa", "Krakow", trains, routes, "06:00", "24:01"),
        std::invalid_argument
    );
}

/**
 * @brief Test walidacji pustych wartości.
 *
 * Sprawdza czy konstruktor klasy Schedule poprawnie rzuca wyjątek
 * std::invalid_argument dla pustych wartości dnia lub nazw stacji.
 */
BOOST_AUTO_TEST_CASE(ScheduleEmptyValuesTest) {
    std::vector<TrainPtr> trains;
    std::vector<RoutePtr> routes;

    BOOST_CHECK_THROW(
        TestSchedule schedule("", "Warszawa", "Krakow", trains, routes, "06:00", "22:00"),
        std::invalid_argument
    );

    BOOST_CHECK_THROW(
        TestSchedule schedule("Poniedzialek", "", "Krakow", trains, routes, "06:00", "22:00"),
        std::invalid_argument
    );

    BOOST_CHECK_THROW(
        TestSchedule schedule("Poniedzialek", "Warszawa", "", trains, routes, "06:00", "22:00"),
        std::invalid_argument
    );
}

/**
 * @brief Test modyfikacji pociągów i tras w rozkładzie.
 *
 * Sprawdza czy metody setTrains() i setRoutes() poprawnie aktualizują
 * kolekcje pociągów i tras w istniejącym rozkładzie jazdy.
 */
BOOST_AUTO_TEST_CASE(ScheduleModifyTrainsAndRoutesTest) {
    std::vector<TrainPtr> trains{std::make_shared<TestTrain>("Express", 1234, 100)};
    std::vector<RoutePtr> routes{std::make_shared<TestRoute>("Warszawa", "Krakow", 2.5, "5")};

    TestSchedule schedule("Poniedzialek", "Warszawa", "Krakow", trains, routes, "06:00", "22:00");


	auto newTrain = std::make_shared<TestTrain>("Lokalny", 5678, 50);
	auto newRoute = std::make_shared<TestRoute>("Krakow", "Gdansk", 4.0, "8");


	std::vector<TrainPtr> updatedTrains = trains;
	updatedTrains.push_back(newTrain);
	std::vector<RoutePtr> updatedRoutes = routes;
	updatedRoutes.push_back(newRoute);


	schedule.setTrains(updatedTrains);
	schedule.setRoutes(updatedRoutes);


	BOOST_CHECK_EQUAL(schedule.getRoutes().size(), 2);


	BOOST_CHECK(!schedule.getTrains().empty());
}

BOOST_AUTO_TEST_SUITE_END()
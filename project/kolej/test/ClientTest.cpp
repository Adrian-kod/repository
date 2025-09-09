/**
 * @file ClientTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klas systemu zarządzania pociągami.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#define BOOST_TEST_MODULE ClientTests
#include <boost/test/unit_test.hpp>
#include "../include/model/Route.h"
#include "../include/model/Train.h"
#include "../include/model/Schedule.h"
#include "../include/model/StudentDiscount.h"
#include "../include/model/WorkerDiscount.h"
#include "../include/model/LargeGoodsTrain.h"
#include <vector>
#include <memory>

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
    ~TestRoute() override {}
};

/**
 * @brief Klasa testowa dziedzicząca po Train.
 *
 * Implementuje abstrakcyjną metodę getInfo() dla celów testowych.
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
    ~TestTrain() override {}

    /**
     * @brief Pobiera informacje o pociągu testowym.
     * @return String zawierający informację "Test Train".
     */
    std::string getInfo() const override { return "Test Train"; }
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
    ~TestSchedule() override {}
};

/**
 * @brief Klasa testowa dziedzicząca po StudentDiscount.
 *
 * Implementuje konkretną wartość zniżki studenckiej dla testów.
 */
class TestStudentDiscount : public StudentDiscount {
public:
    /**
     * @brief Konstruktor klasy TestStudentDiscount.
     */
    TestStudentDiscount() : StudentDiscount() {}

    /**
     * @brief Destruktor klasy TestStudentDiscount.
     */
    ~TestStudentDiscount() override = default;

    /**
     * @brief Pobiera stopień zniżki studenckiej.
     * @return Wartość zniżki jako double (0.5 = 50%).
     */
    double getDiscountRate() const override { return 0.5; }
};

/**
 * @brief Klasa testowa dziedzicząca po WorkerDiscount.
 *
 * Implementuje konkretną wartość zniżki pracowniczej dla testów.
 */
class TestWorkerDiscount : public WorkerDiscount {
public:
    /**
     * @brief Destruktor klasy TestWorkerDiscount.
     */
    ~TestWorkerDiscount() override {}

    /**
     * @brief Pobiera stopień zniżki pracowniczej.
     * @return Wartość zniżki jako double (0.2 = 20%).
     */
    double getDiscountRate() const override { return 0.2; }
};

/**
 * @brief Pakiet testów dla klasy Route.
 *
 * Zawiera testy sprawdzające funkcjonalność tras kolejowych.
 */
BOOST_AUTO_TEST_SUITE(RouteTests)

/**
 * @brief Test ustawiania czasu trwania trasy.
 *
 * Sprawdza czy klasa Route poprawnie obsługuje ustawianie czasu trwania podróży.
 */
BOOST_AUTO_TEST_CASE(RouteSetDurationTest) {
    TestRoute route("Warszawa", "Kraków", 2.5, "5");
}

BOOST_AUTO_TEST_SUITE_END()

/**
 * @brief Pakiet testów dla klasy Train.
 *
 * Zawiera testy sprawdzające funkcjonalność pociągów.
 */
BOOST_AUTO_TEST_SUITE(TrainTests)

/**
 * @brief Test przypisywania miejsc w pociągu.
 *
 * Sprawdza czy klasa Train poprawnie obsługuje zarządzanie miejscami.
 */
BOOST_AUTO_TEST_CASE(TrainAssignSeatsTest) {
    TestTrain train("Express", 1234, 100);
}

BOOST_AUTO_TEST_SUITE_END()

/**
 * @brief Pakiet testów dla klas zniżek.
 *
 * Zawiera testy sprawdzające funkcjonalność różnych typów zniżek.
 */
BOOST_AUTO_TEST_SUITE(DiscountTests)

/**
 * @brief Test zniżki studenckiej.
 *
 * Sprawdza czy klasa StudentDiscount poprawnie oblicza zniżkę dla studentów.
 */
BOOST_AUTO_TEST_CASE(StudentDiscountTest) {
    TestStudentDiscount discount;
}

/**
 * @brief Test zniżki pracowniczej.
 *
 * Sprawdza czy klasa WorkerDiscount poprawnie oblicza zniżkę dla pracowników.
 */
BOOST_AUTO_TEST_CASE(WorkerDiscountTest) {
    TestWorkerDiscount discount;
}

BOOST_AUTO_TEST_SUITE_END()

/**
 * @brief Pakiet testów dla klasy Schedule.
 *
 * Zawiera testy sprawdzające funkcjonalność rozkładów jazdy.
 */
BOOST_AUTO_TEST_SUITE(ScheduleTests)

/**
 * @brief Test konstruktora i getterów klasy Schedule.
 *
 * Sprawdza czy klasa Schedule poprawnie inicjalizuje się i zwraca dane
 * o rozkładzie jazdy.
 */
BOOST_AUTO_TEST_CASE(ScheduleConstructorAndGettersTest) {
    std::vector<std::shared_ptr<Train>> trains;
    std::vector<std::shared_ptr<Route>> routes;
    TestSchedule schedule("Poniedziałek", "Warszawa", "Kraków", trains, routes, "06:00", "22:00");
}

BOOST_AUTO_TEST_SUITE_END()
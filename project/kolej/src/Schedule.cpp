/**
 * @file Schedule.cpp
 * @brief Implementacja klasy Schedule, reprezentującej harmonogram pociągów.
 * @authors Hanna Mikołajczyk i Adrian Tameczka
 * @date 09.06.2025
 */

#include "../include/typedefs.h"
#include "../include/model/Schedule.h"
#include "../include/model/Train.h"
#include "../include/model/Route.h"

/**
 * @brief Konstruktor klasy Schedule.
 *
 * Waliduje podane dane i inicjalizuje pola obiektu.
 *
 * @param day Dzień obowiązywania harmonogramu.
 * @param trains Lista pociągów.
 * @param routes Lista tras.
 * @param firstHour Pierwsza godzina obowiązywania harmonogramu w formacie "GG:MM".
 * @param lastHour Ostatnia godzina obowiązywania harmonogramu w formacie "GG:MM".
 * @param firstStation Nazwa pierwszej stacji.
 * @param lastStation Nazwa ostatniej stacji.
 *
 * @throws std::invalid_argument gdy day, firstStation lub lastStation jest pusty
 *         lub gdy format czasu jest nieprawidłowy.
 */
Schedule::Schedule(const std::string& day,
				   const std::string& firstStation,
				   const std::string& lastStation,
				   const std::vector<TrainPtr>& trains,
				   const std::vector<RoutePtr>& routes,
				   const std::string& firstHour,
				   const std::string& lastHour
				   )
: day(day), firstStation(firstStation), lastStation(lastStation),
	  trains(trains), routes(routes), firstHour(firstHour), lastHour(lastHour)
{
	auto validateTime = [](const std::string& time) {
		if (time.length() != 5 || time[2] != ':') {
			throw std::invalid_argument("Zły format czasu, oczekiwano GG:MM");
		}
		int hours = std::stoi(time.substr(0, 2));
		int minutes = std::stoi(time.substr(3, 2));
		if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
			throw std::invalid_argument("Błędne wartości godzin lub minut");
		}
	};

	validateTime(firstHour);
	validateTime(lastHour);

	if (day.empty() || firstStation.empty() || lastStation.empty()) {
		throw std::invalid_argument("Dzień, pierwsza lub ostatnia stacja nie mogą być puste");
	}
}


/**
 * @brief Wirtualny destruktor klasy Schedule.
 */
Schedule::~Schedule() {}

std::string Schedule::getFirstStation() const
{
    return firstStation;
}

std::string Schedule::getLastStation() const
{
    return lastStation;
}

std::string Schedule::getDay() const
{
    return day;
}

std::vector<TrainPtr> Schedule::getTrains() const {
    return trains;
}

std::vector<RoutePtr> Schedule::getRoutes() const
{
    return routes;
}

std::string Schedule::getFirstHour() const {
    return firstHour;
}

std::string Schedule::getLastHour() const {
    return lastHour;
}

void Schedule::setFirstStation(std::string& station)
{
    firstStation = station;
}

void Schedule::setLastStation(std::string& station)
{
    lastStation = station;
}

void Schedule::setDay(std::string& day)
{
    this->day = day;
}

void Schedule::setTrains(const std::vector<TrainPtr>& trains) {
	this->trains = trains;
}

void Schedule::setRoutes(const std::vector<RoutePtr>& routes)
{
	this->routes = routes;
}

void Schedule::setFirstHour(std::string& hour)
{
    firstHour = hour;
}

void Schedule::setLastHour(std::string& hour)
{
    lastHour = hour;
}

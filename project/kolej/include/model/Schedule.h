/**
 * @file Schedule.h
 * @brief Deklaracja klasy Schedule, reprezentującej harmonogram pociągów.
 * @authors Hanna Mikołajczyki i Adrian Tameczka
 * @date 09.06.2025
 */

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <memory>
#include <vector>
#include "../typedefs.h"

/**
 * @class Schedule
 * @brief Klasa abstrakcyjna reprezentująca harmonogram pociągów.
 *
 * Przechowuje informacje o pierwszej i ostatniej stacji, dniu obowiązywania harmonogramu,
 * liście pociągów oraz tras, a także o przedziale godzin, w których harmonogram jest aktywny.
 */
class Schedule {
private:
	/**
	 * @brief Dzień obowiązywania harmonogramu (np. "Poniedziałek").
	 */
	std::string day;

    /**
     * @brief Nazwa pierwszej stacji.
     */
    std::string firstStation;

    /**
     * @brief Nazwa ostatniej stacji.
     */
    std::string lastStation;

    /**
     * @brief Lista pociągów objętych harmonogramem.
     */
	std::vector<TrainPtr> trains;

    /**
     * @brief Lista tras objętych harmonogramem.
     */
	std::vector<RoutePtr> routes;

    /**
     * @brief Pierwsza godzina obowiązywania harmonogramu (np. "08:00").
     */
    std::string firstHour;

    /**
     * @brief Ostatnia godzina obowiązywania harmonogramu (np. "22:00").
     */
    std::string lastHour;

public:
    /**
     * @brief Konstruktor klasy Schedule.
     * @param day Dzień obowiązywania harmonogramu.
     * @param trains Lista pociągów.
     * @param routes Lista tras.
     * @param firstHour Pierwsza godzina obowiązywania harmonogramu.
     * @param lastHour Ostatnia godzina obowiązywania harmonogramu.
     * @param firstStation Nazwa pierwszej stacji.
     * @param lastStation Nazwa ostatniej stacji.
     */

	Schedule(const std::string& day,
		const std::string& firstStation,
		const std::string& lastStation,
		const std::vector<std::shared_ptr<Train>>& trains,
		const std::vector<std::shared_ptr<Route>>& routes,
		const std::string& firstHour,
		const std::string& lastHour);

    /**
     * @brief Wirtualny destruktor czysto wirtualny (klasa abstrakcyjna).
     */
    virtual ~Schedule();

    /**
     * @brief Zwraca nazwę pierwszej stacji.
     * @return Nazwa pierwszej stacji.
     */
    std::string getFirstStation() const;

    /**
     * @brief Zwraca nazwę ostatniej stacji.
     * @return Nazwa ostatniej stacji.
     */
    std::string getLastStation() const;

    /**
     * @brief Zwraca dzień obowiązywania harmonogramu.
     * @return Dzień jako string.
     */
    std::string getDay() const;

    /**
     * @brief Zwraca listę pociągów.
     * @return Wektor wskaźników do pociągów.
     */
    std::vector<TrainPtr> getTrains() const;

    /**
     * @brief Zwraca listę tras.
     * @return Wektor wskaźników do tras.
     */
    std::vector<RoutePtr> getRoutes() const;

    /**
     * @brief Zwraca pierwszą godzinę obowiązywania harmonogramu.
     * @return Pierwsza godzina jako string.
     */
    std::string getFirstHour() const;

    /**
     * @brief Zwraca ostatnią godzinę obowiązywania harmonogramu.
     * @return Ostatnia godzina jako string.
     */
    std::string getLastHour() const;

    /**
     * @brief Ustawia nazwę pierwszej stacji.
     * @param station Nowa nazwa pierwszej stacji.
     */
    void setFirstStation(std::string& station);

    /**
     * @brief Ustawia nazwę ostatniej stacji.
     * @param station Nowa nazwa ostatniej stacji.
     */
    void setLastStation(std::string& station);

    /**
     * @brief Ustawia dzień obowiązywania harmonogramu.
     * @param day Nowy dzień jako string.
     */
    void setDay(std::string& day);

    /**
     * @brief Ustawia listę pociągów.
     * @param trains Nowa lista pociągów.
     */
	void setTrains(const std::vector<TrainPtr>& trains);

    /**
     * @brief Ustawia listę tras.
     * @param routes Nowa lista tras.
     */
	void setRoutes(const std::vector<RoutePtr>& routes);

    /**
     * @brief Ustawia pierwszą godzinę obowiązywania harmonogramu.
     * @param hour Nowa pierwsza godzina.
     */
    void setFirstHour(std::string& hour);

    /**
     * @brief Ustawia ostatnią godzinę obowiązywania harmonogramu.
     * @param hour Nowa ostatnia godzina.
     */
    void setLastHour(std::string& hour);

};

class ConcreteSchedule : public Schedule {
public:
	ConcreteSchedule(const std::string& day,
					 const std::string& firstStation,
					 const std::string& lastStation,
					 const std::vector<TrainPtr>& trains,
					 const std::vector<RoutePtr>& routes,
					 const std::string& firstHour,
					 const std::string& lastHour)
		: Schedule(day, firstStation, lastStation, trains, routes, firstHour, lastHour) {}

	~ConcreteSchedule() override {}
};

#endif // SCHEDULE_H


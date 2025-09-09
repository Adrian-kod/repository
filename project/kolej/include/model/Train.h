/**
 * @file Train.h
 * @brief Definicja klasy Train reprezentującej pociąg.
 * @author Hanna Mikołajczyk i Adrian Tameczka
 * @date 16.06.2025
 */

#ifndef TRAIN_H
#define TRAIN_H

#include "../typedefs.h"
#include <string>

/**
 * @class Train
 * @brief Klasa reprezentująca pociąg.
 *
 * Klasa Train przechowuje informacje o pociągu, takie jak nazwa, numer pociągu, liczba miejsc oraz liczba dostępnych miejsc.
 * Jest to klasa abstrakcyjna, dostarczająca interfejs dla klas pochodnych.
 */
class Train {
private:
    int seats; ///< Całkowita liczba miejsc w pociągu.
    int trainNumber; ///< Numer pociągu.
    std::string name; ///< Nazwa pociągu.
    int availableSeats; ///< Liczba dostępnych miejsc w pociągu.

public:
    /**
     * @brief Konstruktor klasy Train.
     * @param name Nazwa pociągu.
     * @param trainNumber Numer pociągu.
     * @param seats Całkowita liczba miejsc w pociągu.
     */
    Train(std::string name, int trainNumber, int seats);

    /**
     * @brief Czysto wirtualny destruktor klasy Train.
     */
    virtual ~Train() = 0;

    /**
     * @brief Pobiera całkowitą liczbę miejsc w pociągu.
     * @return Liczba miejsc jako int.
     */
    int getSeats() const;

    /**
     * @brief Pobiera numer pociągu.
     * @return Numer pociągu jako int.
     */
    int getTrainNumber() const;

    /**
     * @brief Pobiera nazwę pociągu.
     * @return Nazwa pociągu jako std::string.
     */
    std::string getName() const;

    /**
     * @brief Pobiera liczbę dostępnych miejsc w pociągu.
     * @return Liczba dostępnych miejsc jako int.
     */
    virtual int getAvailableSeats() const;

    /**
     * @brief Pobiera informacje o pociągu.
     * @return Informacje o pociągu jako std::string.
     */
    virtual std::string getInfo() const = 0;

    /**
     * @brief Ustawia całkowitą liczbę miejsc w pociągu.
     * @param seats Nowa liczba miejsc.
     */
    void setSeats(int seats);

    /**
     * @brief Ustawia numer pociągu.
     * @param trainNumber Nowy numer pociągu.
     */
    void setTrainNumber(int trainNumber);

    /**
     * @brief Ustawia nazwę pociągu.
     * @param name Nowa nazwa pociągu.
     */
    void setName(const std::string& name);

    /**
     * @brief Ustawia liczbę dostępnych miejsc w pociągu.
     * @param availableSeats Nowa liczba dostępnych miejsc.
     */
    void setAvailableSeats(int availableSeats);

    /**
     * @brief Przydziela miejsca w pociągu.
     * @return Informacja o przydzielonych miejscach jako std::string.
     */
    std::string assignSeats();
};

#endif //TRAIN_H
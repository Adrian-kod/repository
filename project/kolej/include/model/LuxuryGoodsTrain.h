/**
 * @file LuxuryGoodsTrain.h
 * @brief Deklaracja klasy LuxuryGoodsTrain, reprezentującej luksusowy pociąg towarowy z ochroną.
 * @authors Hanna Mikołajczyk, Adrian Tameczka
 * @date 11.06.2025
 */

#ifndef LUXURYGOODSTRAIN_H
#define LUXURYGOODSTRAIN_H

#include "GoodsTrain.h"

/**
 * @class LuxuryGoodsTrain
 * @brief Klasa reprezentująca luksusowy pociąg towarowy z możliwością włączenia ochrony.
 *
 * Dziedziczy po GoodsTrain. Dodaje mechanizm ochrony (`securityEnabled`), który może być aktywowany.
 */
class LuxuryGoodsTrain : public GoodsTrain {
private:
    /**
     * @brief Flaga określająca, czy ochrona pociągu została włączona.
     */
    bool securityEnabled;

public:
    /**
     * @brief Konstruktor parametryczny klasy LuxuryGoodsTrain.
     *
     * @param name Nazwa pociągu.
     * @param trainNumber Numer identyfikacyjny pociągu.
     * @param seats Liczba miejsc (jeśli dotyczy).
     * @param courrentLoadKg Aktualne obciążenie pociągu w kilogramach.
     * @param maxLoadKg Maksymalne dopuszczalne obciążenie.
     * @param securityEnabled Czy ochrona została włączona podczas tworzenia.
     */
    LuxuryGoodsTrain(const std::string& name, int trainNumber, int seats, double currentLoadKg, double maxLoadKg, bool securityEnabled);

    /**
     * @brief Domyślny destruktor wirtualny.
     */
    virtual ~LuxuryGoodsTrain() = default;

    /**
     * @brief Zwraca informacje o pociągu, w tym status ochrony.
     *
     * @return Tekst zawierający dane o pociągu.
     */
    std::string getInfo() const override;

    /**
     * @brief Aktywuje ochronę w luksusowym pociągu towarowym.
     */
    void enableSecurity();
};

#endif // LUXURYGOODSTRAIN_H

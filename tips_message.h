#ifndef TIPS_MESSAGE_H
#define TIPS_MESSAGE_H
#include "enemy.h"
#include "your_hero.h"

/**
 * @brief Struktura przechwoujaca wiadomosc dla okna Podpowiedzi
 */
struct Tips_message
{
    /**
     * @brief Pole zawierajace uchwyt do tablicy przeciwnikow
     */
    Enemy *enemies;
    /**
     * @brief Pole zawierajace obiekt reprezentujacy postac aktywnego gracza
     */
    Your_hero your_hero;
};





#endif // TIPS_MESSAGE_H

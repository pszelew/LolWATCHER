#include "your_hero.h"

Your_hero::Your_hero(): skin_id(INT_MAX), lore("")
{
    attack_series = new QLineSeries;
    gold_series = new QLineSeries;
}

#include "your_hero.h"

Your_hero::Your_hero(): lore(""), skin_id(INT_MAX)
{
    attack_series = new QLineSeries;
    gold_series = new QLineSeries;
}

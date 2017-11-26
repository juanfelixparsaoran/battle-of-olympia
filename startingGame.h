#ifndef STARTINGGAME_H
#define STARTINGGAME_H

#include "matriksPetak.h"
#include "point.h"

#include "villages.h"
#include "map.h"
#include "unit.h"
#include "unitlist.h"
#include "player.h"

#include <stdlib.h>
#include <time.h>

void setStartGame(MAP *M, Player *P1, Player *P2);

void setElement(MAP *M, POINT index, char type,int owner);

#endif

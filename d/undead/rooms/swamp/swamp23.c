#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "east":SWMP+"swamp24",
        "west":SWMP+"swamp39",
        "south":SWMP+"swamp22",
             ]));

}


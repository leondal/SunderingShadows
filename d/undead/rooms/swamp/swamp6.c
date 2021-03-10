#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "west"      :SWMP+"swamp51",
        "north"     :SWMP+"swamp7",
        "south"     :SWMP+"swamp5",
             ]));

}


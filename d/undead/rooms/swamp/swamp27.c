#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "north"     :SWMP+"swamp29",
        "west"      :SWMP+"swamp52",
        "south"     :SWMP+"swamp39",
             ]));

}


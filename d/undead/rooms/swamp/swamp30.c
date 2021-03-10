#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "north"     :SWMP+"swamp34",
        "east"      :SWMP+"swamp31",
        "west"      :SWMP+"swamp60",
        "south"     :SWMP+"swamp29",
             ]));

}


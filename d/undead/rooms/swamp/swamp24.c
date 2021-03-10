#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "east"      :SWMP+"swamp38",
        "west"      :SWMP+"swamp23",
        "north"     :SWMP+"swamp25",
             ]));

}


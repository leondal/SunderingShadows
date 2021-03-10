#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "northwest" :SWMP+"swamp17",
        "northeast" :SWMP+"swamp51",
        "east"      :SWMP+"swamp19",
             ]));

}


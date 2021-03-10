#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "northeast" :SWMP+"swamp50",
        "east"      :SWMP+"swamp13",
        "west"      :SWMP+"swamp37",
        "south"     :SWMP+"swamp15",
             ]));

}


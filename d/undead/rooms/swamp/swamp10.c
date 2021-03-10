#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "east"      :SWMP+"swamp11",
        "northwest" :SWMP+"swamp50",
        "south"     :SWMP+"swamp9",
        "west"      :SWMP+"swamp13",
             ]));

}

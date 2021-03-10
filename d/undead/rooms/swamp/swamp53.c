#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "east"      :SWMP+"swamp52",
        "northwest" :SWMP+"swamp57",
        "south"     :SWMP+"swamp54",
             ]));

}

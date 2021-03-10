#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "north"     :SWMP+"swamp9",
        "northwest" :SWMP+"swamp12",
        "east"      :SWMP+"swamp7",
             ]));

}

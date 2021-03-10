#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "up"        :MTS+"room107",
        "northeast" :SWMP+"swamp2",
        "northwest" :SWMP+"swamp21",
             ]));

}


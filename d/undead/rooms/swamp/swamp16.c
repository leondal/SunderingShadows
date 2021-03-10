#include "../../undead.h"

inherit INH+"swamp_one.c";


void create() 
{
   ::create();

    set_exits(([
        "northwest" :SWMP+"swamp33",
        "northeast" :SWMP+"swamp12",
        "north"     :SWMP+"swamp15",
        "south"     :SWMP+"swamp17",
             ]));

}

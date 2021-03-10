#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "northeast" :SWMP+"swamp19",
        "southeast" :SWMP+"swamp3",
        "west"      :SWMP+"swamp38",
             ]));

}

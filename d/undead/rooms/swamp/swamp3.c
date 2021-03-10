#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "northeast" :SWMP+"swamp4",
        "northwest" :SWMP+"swamp20",
        "west"      :SWMP+"swamp2",
             ]));

}

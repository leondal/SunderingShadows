#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "north"     :SWMP+"swamp16",
        "southeast" :SWMP+"swamp18",
        "southwest" :SWMP+"swamp25",
             ]));

}

#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "north"     :SWMP+"swamp6",
        "south"     :SWMP+"swamp4",
             ]));

}

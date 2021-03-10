#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "north"     :SWMP+"swamp10",
        "south"     :SWMP+"swamp8",
             ]));

}

#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "northeast" :SWMP+"swamp33",
        "south"     :SWMP+"swamp31",
             ]));

}

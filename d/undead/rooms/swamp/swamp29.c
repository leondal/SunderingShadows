#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "east"      :SWMP+"swamp28",
        "north"     :SWMP+"swamp30",
        "south"     :SWMP+"swamp27",
             ]));

}

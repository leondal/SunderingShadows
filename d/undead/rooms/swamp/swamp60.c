#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "east"      :SWMP+"swamp30",
        "west"      :SWMP+"swamp59",
        "south"     :SWMP+"swamp61",
             ]));

}

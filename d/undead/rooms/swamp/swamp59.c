#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "east"      :SWMP+"swamp60",
        "west"      :SWMP+"swamp58",
             ]));

}

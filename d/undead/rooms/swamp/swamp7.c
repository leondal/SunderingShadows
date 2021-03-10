#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "west"      :SWMP+"swamp8",
        "south"     :SWMP+"swamp6",
             ]));

}


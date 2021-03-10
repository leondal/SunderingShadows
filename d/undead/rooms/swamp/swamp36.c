#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "north"     :SWMP+"swamp40",
        "west"      :SWMP+"swamp35",
             ]));

}


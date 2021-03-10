#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "southeast" :SWMP+"swamp55",
        "north"     :SWMP+"swamp53",
        "west"      :SWMP+"swamp56",
             ]));

}

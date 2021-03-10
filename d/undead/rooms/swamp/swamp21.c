#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "west"      :SWMP+"swamp22",
        "southeast" :SWMP+"swamp1",
             ]));

}

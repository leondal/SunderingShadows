#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "east"      :SWMP+"swamp20",
        "west"      :SWMP+"swamp24",
             ]));

}

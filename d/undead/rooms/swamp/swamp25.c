#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "west"      :SWMP+"swamp26",
        "south"     :SWMP+"swamp24",
        "northeast" :SWMP+"swamp17",
             ]));

}

#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
    ::create();

    set_exits(([
        "southeast" :SWMP+"swamp10",
        "southwest" :SWMP+"swamp14",
             ]));

}

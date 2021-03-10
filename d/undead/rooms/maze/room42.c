#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "south"     :MAZ+"room8",
        "northeast" :MAZ+"room21",
        "northwest" :MAZ+"room19",
        "southeast" :MAZ+"room35"
             ]));

}

#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room41",
        "east"      :MAZ+"room36",
        "south"     :MAZ+"room32",
        "northwest" :MAZ+"room42",
        "southeast" :MAZ+"room6"
             ]));

}

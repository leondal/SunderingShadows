#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_exits(([
        "north"     :MAZ+"room8",
        "east"      :MAZ+"room32",
        "west"      :MAZ+"room30",
        "northwest" :MAZ+"room27"
             ]));

}

#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "northwest" :MAZ+"room30",
        "south"     :MAZ+"room34"
             ]));

}

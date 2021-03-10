#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_exits(([
        "west"      :MAZ+"room16",
        "south"     :MAZ+"room21",
        "southwest" :MAZ+"room20"
             ]));

}

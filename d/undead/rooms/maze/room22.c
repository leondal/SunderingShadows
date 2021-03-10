#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_exits(([
        "east"      :MAZ+"room23",
        "west"      :MAZ+"room21",
        "southwest" :MAZ+"room41"
             ]));

}

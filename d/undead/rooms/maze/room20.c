#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_exits(([
        "northeast" :MAZ+"room9",
        "east"      :MAZ+"room21",
        "west"      :MAZ+"room19"
             ]));

}

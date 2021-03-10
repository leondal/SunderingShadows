#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_exits(([
        "east"      :MAZ+"room37",
        "west"      :MAZ+"room35"
             ]));

}

#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "west"      :MAZ+"room25",
        "east"      :MAZ+"room27",
        "northwest" :MAZ+"room5"
             ]));

}

#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room15",
        "east"      :MAZ+"room20",
        "west"      :MAZ+"room18",
        "southeast" :MAZ+"room42"
             ]));

}

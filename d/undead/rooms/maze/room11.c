#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room10",
        "east"      :MAZ+"room12",
        "south"     :MAZ+"room14",
        "west"      :MAZ+"room7",
        "southeast" :MAZ+"room15",
        "southwest" :MAZ+"room13"
             ]));

}

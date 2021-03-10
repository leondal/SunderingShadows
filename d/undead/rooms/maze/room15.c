#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room12",
        "east"      :MAZ+"room16",
        "south"     :MAZ+"room19",
        "northwest" :MAZ+"room11"
             ]));
}

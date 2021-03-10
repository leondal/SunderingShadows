#include "../../undead.h"

inherit INH+"maze_one.c";

void create()
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room11",
        "south"     :MAZ+"room18"
             ]));

}

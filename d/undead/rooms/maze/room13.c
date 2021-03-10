#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room5",
        "south"     :MAZ+"room17",
        "northeast" :MAZ+"room11"
             ]));

}

#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room14",
        "east"      :MAZ+"room19",
        "west"      :MAZ+"room17"
             ]));

}

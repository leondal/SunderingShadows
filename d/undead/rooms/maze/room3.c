#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "south"     :MAZ+"room25",
        "southeast" :MAZ+"room26"
             ]));

}

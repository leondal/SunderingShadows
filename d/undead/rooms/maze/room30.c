#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    set_exits(([
        "east"      :MAZ+"room31",
        "southeast" :MAZ+"room33",
        "southwest" :MAZ+"room"
             ]));

}

#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    set_exits(([
        "east"      :MAZ+"room11",
        "south"     :MAZ+"room13"
             ]));

}

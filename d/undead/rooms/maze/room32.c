#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room35",
        "east"      :MAZ+"room6",
        "west"      :MAZ+"room31",
        "south"     :MAZ+"room44"
             ]));

}

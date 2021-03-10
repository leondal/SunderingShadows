#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room5",
        "east"      :MAZ+"room26",
        "west"      :MAZ+"room24",
        "south"     :MAZ+"room28"
             ]));

}

#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room40",
        "east"      :MAZ+"room38",
        "west"      :MAZ+"room36"
             ]));

}

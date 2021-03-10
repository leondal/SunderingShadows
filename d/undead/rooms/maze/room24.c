#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :MAZ+"room43",
        "west"      :MAZ+"room2",
        "east"      :MAZ+"room25"
             ]));

}

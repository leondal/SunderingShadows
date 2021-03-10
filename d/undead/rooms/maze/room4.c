#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "west"      :MAZ+"room5",
        "south"     :MAZ+"room5"
             ]));

}

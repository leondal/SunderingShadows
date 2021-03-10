#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "south"     :MAZ+"room35",
        "northeast" :MAZ+"room22"
             ]));

}

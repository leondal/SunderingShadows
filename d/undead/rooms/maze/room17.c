#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_exits(([
        "north"     :MAZ+"room13",
        "east"      :MAZ+"room18",
        "southwest" :MAZ+"room43"
             ]));

}

#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
    
    set_exits(([
        "north"     :MAZ+"room9",
        "east"      :MAZ+"room22",
        "west"      :MAZ+"room20",
        "southwest" :MAZ+"room42"
             ]));

}

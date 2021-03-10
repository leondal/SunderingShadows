#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
   
    set_exits(([
        "east"      :MAZ+"room4",
        "west"      :MAZ+"room22",
        "south"     :MAZ+"room40"
             ]));

}

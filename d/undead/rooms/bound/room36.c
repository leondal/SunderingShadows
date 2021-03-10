#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room35",
        "south"     :BF+"room32",
        "east"      :BO+"room34"
             ]));

}

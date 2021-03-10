#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room32",
        "east"      :BO+"room31",
        "south"     :BO+"room34",
        "west"      :BO+"room35"
             ]));

}

#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path",
        "east"      :BO+"room41",
        "south"     :BO+"room31",
        "west"      :BO+"room32"
             ]));

}

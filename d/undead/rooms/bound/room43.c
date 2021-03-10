#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room44",
        "south"     :BO+"room47",
        "west"      :BO+"room42"
             ]));

}

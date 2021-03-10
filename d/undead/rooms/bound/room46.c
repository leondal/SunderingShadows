#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room42",
        "east"      :BO+"room47",
        "south"     :BO+"room49",
        "west"      :BO+"room45"
             ]));

}

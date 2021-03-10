#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room48",
        "north"     :BO+"room31",
        "south"     :BO+"room3",
        "west"      :BO+"room34"
             ]));

}

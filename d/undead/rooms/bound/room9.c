#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :BO+"room10",
        "west"      :BO+"room8"
             ]));

}

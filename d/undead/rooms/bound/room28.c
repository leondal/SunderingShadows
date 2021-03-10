#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room6",
        "east"      :BO+"room8",
        "south"     :BO+"room27",
        "west"      :BO+"room29"
             ]));

}

#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"room21",
        "south"     :TOWN+"room23"
             ]));

}

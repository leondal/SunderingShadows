#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"room18",
        "south"     :TOWN+"room21"
             ]));

}

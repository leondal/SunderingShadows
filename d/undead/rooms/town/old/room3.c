#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"room10",
        "east"      :TOWN+"room7",
        "south"     :TOWN+"room2",
        "west"      :TOWN+"room4"
             ]));

}

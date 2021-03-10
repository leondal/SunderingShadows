#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"room12",
        "east"      :TOWN+"ware3",
        "south"     :TOWN+"room10",
        "west"      :TOWN+"ware"
             ]));

}

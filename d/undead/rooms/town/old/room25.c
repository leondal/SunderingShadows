#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"room24",
        "east"      :TOWN+"guard9",
        "south"     :TOWN+"room26"
             ]));

}

#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"room8",
        "east"      :TOWN+"guard12",
        "west"      :TOWN+"guard2"
             ]));

}

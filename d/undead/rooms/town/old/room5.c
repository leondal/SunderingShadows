#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"bank",
        "east"      :TOWN+"room4",
        "south"     :TOWN+"room6",
        "west"      :TOWN+"room19"
             ]));

}

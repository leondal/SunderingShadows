#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"room11",
        "east"      :TOWN+"ware4",
        "south"     :TOWN+"room3",
        "west"      :TOWN+"ware2"
             ]));

}

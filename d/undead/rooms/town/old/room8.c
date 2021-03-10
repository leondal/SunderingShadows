#include "../../undead.h"

inherit INH+"town_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"pub",
        "east"      :TOWN+"room28",
        "south"     :TOWN+"room9",
        "west"      :TOWN+"room7"
             ]));

}

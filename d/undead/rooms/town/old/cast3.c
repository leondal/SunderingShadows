#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"cast4",
        "south"     :TOWN+"cast2"
             ]));

}

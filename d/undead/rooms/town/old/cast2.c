#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"cast3",
        "south"     :TOWN+"cast"
             ]));

}

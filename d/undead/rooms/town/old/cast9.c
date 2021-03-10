#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"cast10",
        "south"     :TOWN+"cast7"
             ]));

}

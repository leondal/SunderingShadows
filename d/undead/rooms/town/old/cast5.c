#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"cast10",
        "east"      :TOWN+"cast4",
        "west"      :TOWN+"cast7"
             ]));

}

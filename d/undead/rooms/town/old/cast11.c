#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"cast14",
        "east"      :TOWN+"cast12",
        "south"     :TOWN+"cast4",
        "west"      :TOWN+"cast10"
             ]));

}

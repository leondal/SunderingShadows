#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"cast12",
        "east"      :TOWN+"cast8",
        "west"      :TOWN+"cast4"
             ]));

}

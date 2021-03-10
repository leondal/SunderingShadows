#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"cast11",
        "south"     :TOWN+"cast5",
        "west"      :TOWN+"cast9"
             ]));

}

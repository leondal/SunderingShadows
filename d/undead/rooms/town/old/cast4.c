#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"cast11",
        "east"      :TOWN+"cast6",
        "south"     :TOWN+"cast3",
        "west"      :TOWN+"cast5"
             ]));

}

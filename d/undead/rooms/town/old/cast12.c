#include "../../undead.h"

inherit INH+"town_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"cast13",
        "south"     :TOWN+"cast6",
        "west"      :TOWN+"cast11"
             ]));

}

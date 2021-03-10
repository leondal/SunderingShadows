#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,10",
        "east"      :DES+"desert_8,11",
        "south"     :DES+"desert_9,10",
        "west"      :DES+"desert_8,9"
             ]));
}
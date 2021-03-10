#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,11",
        "east"      :DES+"desert_8,12",
        "south"     :DES+"desert_9,11",
        "west"      :DES+"desert_8,10"
             ]));
}
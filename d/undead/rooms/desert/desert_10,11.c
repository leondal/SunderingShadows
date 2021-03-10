#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,11",
        "east"      :DES+"desert_10,12",
        "south"     :DES+"desert_11,11",
        "west"      :DES+"desert_10,10"
             ]));
}
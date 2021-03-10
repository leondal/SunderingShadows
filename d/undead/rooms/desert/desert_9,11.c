#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,11",
        "east"      :DES+"desert_9,12",
        "south"     :DES+"desert_10,11",
        "west"      :DES+"desert_9,10"
             ]));
}
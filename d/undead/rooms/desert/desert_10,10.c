#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,10",
        "east"      :DES+"desert_10,11",
        "south"     :DES+"desert_11,10",
        "west"      :DES+"desert_10,9"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,10",
        "east"      :DES+"desert_9,11",
        "south"     :DES+"desert_10,10",
        "west"      :DES+"desert_9,9"
             ]));
}
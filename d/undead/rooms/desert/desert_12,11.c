#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,11",
        "east"      :DES+"desert_12,12",
        "south"     :DES+"desert_13,11",
        "west"      :DES+"desert_12,10"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,11",
        "east"      :DES+"desert_13,12",
        "south"     :DES+"desert_14,11",
        "west"      :DES+"desert_13,10"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,10",
        "east"      :DES+"desert_13,11",
        "south"     :DES+"desert_14,10",
        "west"      :DES+"desert_13,9"
             ]));
}
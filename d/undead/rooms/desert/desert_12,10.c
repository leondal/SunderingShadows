#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,10",
        "east"      :DES+"desert_12,11",
        "south"     :DES+"desert_13,10",
        "west"      :DES+"desert_12,9"
             ]));
}
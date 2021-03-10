#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,10",
        "east"      :DES+"desert_11,11",
        "south"     :DES+"desert_12,10",
        "west"      :DES+"desert_11,9"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,11",
        "east"      :DES+"desert_11,12",
        "south"     :DES+"desert_12,11",
        "west"      :DES+"desert_11,10"
             ]));
}
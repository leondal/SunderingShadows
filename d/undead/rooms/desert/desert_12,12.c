#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,12",
        "east"      :DES+"desert_12,13",
        "south"     :DES+"desert_13,12",
        "west"      :DES+"desert_12,11"
             ]));
}
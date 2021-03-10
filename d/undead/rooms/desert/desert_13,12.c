#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,12",
        "east"      :DES+"desert_13,13",
        "south"     :DES+"desert_14,12",
        "west"      :DES+"desert_13,11"
             ]));
}
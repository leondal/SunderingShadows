#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,12",
        "east"      :DES+"desert_11,13",
        "south"     :DES+"desert_12,12",
        "west"      :DES+"desert_11,11"
             ]));
}
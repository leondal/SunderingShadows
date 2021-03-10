#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,13",
        "east"      :DES+"desert_12,14",
        "south"     :DES+"desert_13,13",
        "west"      :DES+"desert_12,12"
             ]));
}
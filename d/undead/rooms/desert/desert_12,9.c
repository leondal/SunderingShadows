#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,9",
        "east"      :DES+"desert_12,10",
        "south"     :DES+"desert_13,9",
        "west"      :DES+"desert_12,8"
             ]));
}
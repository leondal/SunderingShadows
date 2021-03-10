#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,9",
        "east"      :DES+"desert_13,10",
        "south"     :DES+"desert_14,9",
        "west"      :DES+"desert_13,8"
             ]));
}
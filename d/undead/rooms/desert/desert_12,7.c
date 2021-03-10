#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,7",
        "east"      :DES+"desert_12,8",
        "south"     :DES+"desert_13,7",
        "west"      :DES+"desert_12,6"
             ]));
}
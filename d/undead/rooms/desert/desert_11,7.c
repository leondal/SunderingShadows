#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,7",
        "east"      :DES+"desert_11,8",
        "south"     :DES+"desert_12,7",
        "west"      :DES+"desert_11,6"
             ]));
}
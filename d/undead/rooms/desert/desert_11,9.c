#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,9",
        "east"      :DES+"desert_11,10",
        "south"     :DES+"desert_12,9",
        "west"      :DES+"desert_11,8"
             ]));
}
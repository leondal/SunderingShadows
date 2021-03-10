#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,8",
        "east"      :DES+"desert_13,9",
        "south"     :DES+"desert_14,8",
        "west"      :DES+"desert_13,7"
             ]));
}
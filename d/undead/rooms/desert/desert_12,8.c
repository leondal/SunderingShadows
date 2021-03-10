#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,8",
        "east"      :DES+"desert_12,9",
        "south"     :DES+"desert_13,8",
        "west"      :DES+"desert_12,7"
             ]));
}
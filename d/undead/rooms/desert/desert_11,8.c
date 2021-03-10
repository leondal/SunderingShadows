#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,8",
        "east"      :DES+"desert_11,9",
        "south"     :DES+"desert_12,8",
        "west"      :DES+"desert_11,7"
             ]));
}
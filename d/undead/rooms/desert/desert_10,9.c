#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,9",
        "east"      :DES+"desert_10,10",
        "south"     :DES+"desert_11,9",
        "west"      :DES+"desert_10,8"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,9",
        "east"      :DES+"desert_8,10",
        "south"     :DES+"desert_9,9",
        "west"      :DES+"desert_8,8"
             ]));
}
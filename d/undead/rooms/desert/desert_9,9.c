#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,9",
        "east"      :DES+"desert_9,10",
        "south"     :DES+"desert_10,9",
        "west"      :DES+"desert_9,8"
             ]));
}
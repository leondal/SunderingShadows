#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,7",
        "east"      :DES+"desert_9,8",
        "south"     :DES+"desert_10,7",
        "west"      :DES+"desert_9,6"
             ]));
}
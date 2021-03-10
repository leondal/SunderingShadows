#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,7",
        "east"      :DES+"desert_8,8",
        "south"     :DES+"desert_9,7",
        "west"      :DES+"desert_8,6"
             ]));
}
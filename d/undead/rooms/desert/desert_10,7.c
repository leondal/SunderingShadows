#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,7",
        "east"      :DES+"desert_10,8",
        "south"     :DES+"desert_11,7",
        "west"      :DES+"desert_10,6"
             ]));
}
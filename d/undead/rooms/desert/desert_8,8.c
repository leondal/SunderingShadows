#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,8",
        "east"      :DES+"desert_8,9",
        "south"     :DES+"desert_9,8",
        "west"      :DES+"desert_8,7"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,8",
        "east"      :DES+"desert_9,9",
        "south"     :DES+"desert_10,8",
        "west"      :DES+"desert_9,7"
             ]));
}
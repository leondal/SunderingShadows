#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,8",
        "east"      :DES+"desert_10,9",
        "south"     :DES+"desert_11,8",
        "west"      :DES+"desert_10,7"
             ]));
}
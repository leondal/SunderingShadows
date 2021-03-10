#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,12",
        "east"      :DES+"desert_10,13",
        "south"     :DES+"desert_11,12",
        "west"      :DES+"desert_10,11"
             ]));
}
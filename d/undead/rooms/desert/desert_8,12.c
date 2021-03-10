#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,12",
        "east"      :DES+"desert_8,13",
        "south"     :DES+"desert_9,12",
        "west"      :DES+"desert_8,11"
             ]));
}
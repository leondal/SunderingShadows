#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,12",
        "east"      :DES+"desert_9,13",
        "south"     :DES+"desert_10,12",
        "west"      :DES+"desert_9,11"
             ]));
}
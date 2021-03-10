#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,13",
        "east"      :DES+"desert_8,14",
        "south"     :DES+"desert_9,13",
        "west"      :DES+"desert_8,12"
             ]));
}
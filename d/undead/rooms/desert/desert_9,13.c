#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,13",
        "east"      :DES+"desert_9,14",
        "south"     :DES+"desert_10,13",
        "west"      :DES+"desert_9,12"
             ]));
}
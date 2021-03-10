#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,13",
        "east"      :DES+"desert_10,14",
        "south"     :DES+"desert_11,13",
        "west"      :DES+"desert_10,12"
             ]));
}
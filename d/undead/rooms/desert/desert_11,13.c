#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,13",
        "east"      :DES+"desert_11,14",
        "south"     :DES+"desert_12,13",
        "west"      :DES+"desert_11,12"
             ]));
}
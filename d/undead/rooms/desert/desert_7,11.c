#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,11",
        "east"      :DES+"desert_7,12",
        "south"     :DES+"desert_8,11",
        "west"      :DES+"desert_7,10"
             ]));
}
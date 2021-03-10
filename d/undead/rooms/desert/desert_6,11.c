#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,11",
        "east"      :DES+"desert_6,12",
        "south"     :DES+"desert_7,11",
        "west"      :DES+"desert_6,10"
             ]));
}
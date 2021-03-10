#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,11",
        "east"      :DES+"desert_4,12",
        "south"     :DES+"desert_5,11",
        "west"      :DES+"desert_4,10"
             ]));
}
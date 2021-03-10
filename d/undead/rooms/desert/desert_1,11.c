#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,11",
        "east"      :DES+"desert_1,12",
        "south"     :DES+"desert_2,11",
        "west"      :DES+"desert_1,10"
             ]));
}
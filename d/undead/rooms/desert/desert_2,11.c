#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,11",
        "east"      :DES+"desert_2,12",
        "south"     :DES+"desert_3,11",
        "west"      :DES+"desert_2,10"
             ]));
}
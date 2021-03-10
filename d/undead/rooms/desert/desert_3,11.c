#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,11",
        "east"      :DES+"desert_3,12",
        "south"     :DES+"desert_4,11",
        "west"      :DES+"desert_3,10"
             ]));
}
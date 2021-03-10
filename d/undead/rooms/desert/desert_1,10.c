#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,10",
        "east"      :DES+"desert_1,11",
        "south"     :DES+"desert_2,10",
        "west"      :DES+"desert_1,9"
             ]));
}
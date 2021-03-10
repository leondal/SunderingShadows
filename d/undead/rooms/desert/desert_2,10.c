#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,10",
        "east"      :DES+"desert_2,11",
        "south"     :DES+"desert_3,10",
        "west"      :DES+"desert_2,9"
             ]));
}
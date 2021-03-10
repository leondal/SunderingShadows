#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,10",
        "east"      :DES+"desert_3,11",
        "south"     :DES+"desert_4,10",
        "west"      :DES+"desert_3,9"
             ]));
}
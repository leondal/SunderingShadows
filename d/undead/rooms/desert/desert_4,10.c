#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,10",
        "east"      :DES+"desert_4,11",
        "south"     :DES+"desert_5,10",
        "west"      :DES+"desert_4,9"
             ]));
}
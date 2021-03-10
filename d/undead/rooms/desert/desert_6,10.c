#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,10",
        "east"      :DES+"desert_6,11",
        "south"     :DES+"desert_7,10",
        "west"      :DES+"desert_6,9"
             ]));
}
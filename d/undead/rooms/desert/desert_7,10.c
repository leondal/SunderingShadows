#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,10",
        "east"      :DES+"desert_7,11",
        "south"     :DES+"desert_8,10",
        "west"      :DES+"desert_7,9"
             ]));
}
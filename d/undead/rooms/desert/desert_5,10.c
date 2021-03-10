#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,10",
        "east"      :DES+"desert_5,11",
        "south"     :DES+"desert_6,10",
        "west"      :DES+"desert_5,9"
             ]));
}
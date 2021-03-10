#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,11",
        "east"      :DES+"desert_5,12",
        "south"     :DES+"desert_6,11",
        "west"      :DES+"desert_5,10"
             ]));
}
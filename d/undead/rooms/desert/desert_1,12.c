#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,12",
        "east"      :DES+"desert_1,13",
        "south"     :DES+"desert_2,12",
        "west"      :DES+"desert_1,11"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,12",
        "east"      :DES+"desert_2,13",
        "south"     :DES+"desert_3,12",
        "west"      :DES+"desert_2,11"
             ]));
}
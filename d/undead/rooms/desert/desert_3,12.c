#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,12",
        "east"      :DES+"desert_3,13",
        "south"     :DES+"desert_4,12",
        "west"      :DES+"desert_3,11"
             ]));
}
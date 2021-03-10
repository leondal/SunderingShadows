#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,12",
        "east"      :DES+"desert_4,13",
        "south"     :DES+"desert_5,12",
        "west"      :DES+"desert_4,11"
             ]));
}
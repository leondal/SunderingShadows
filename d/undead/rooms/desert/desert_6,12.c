#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,12",
        "east"      :DES+"desert_6,13",
        "south"     :DES+"desert_7,12",
        "west"      :DES+"desert_6,11"
             ]));
}
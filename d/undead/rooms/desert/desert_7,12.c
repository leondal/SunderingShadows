#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,12",
        "east"      :DES+"desert_7,13",
        "south"     :DES+"desert_8,12",
        "west"      :DES+"desert_7,11"
             ]));
}
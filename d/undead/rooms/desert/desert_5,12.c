#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,12",
        "east"      :DES+"desert_5,13",
        "south"     :DES+"desert_6,12",
        "west"      :DES+"desert_5,11"
             ]));
}
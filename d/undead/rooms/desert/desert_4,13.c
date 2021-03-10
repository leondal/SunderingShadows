#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,13",
        "east"      :DES+"desert_4,14",
        "south"     :DES+"desert_5,13",
        "west"      :DES+"desert_4,12"
             ]));
}
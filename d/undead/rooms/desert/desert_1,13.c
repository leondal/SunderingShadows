#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,13",
        "east"      :DES+"desert_1,14",
        "south"     :DES+"desert_2,13",
        "west"      :DES+"desert_1,12"
             ]));
}
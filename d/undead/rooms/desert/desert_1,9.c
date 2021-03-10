#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,9",
        "east"      :DES+"desert_1,10",
        "south"     :DES+"desert_2,9",
        "west"      :DES+"desert_1,8"
             ]));
}
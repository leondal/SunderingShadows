#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,9",
        "east"      :DES+"desert_2,10",
        "south"     :DES+"desert_3,9",
        "west"      :DES+"desert_2,8"
             ]));
}
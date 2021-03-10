#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,9",
        "east"      :DES+"desert_3,10",
        "south"     :DES+"desert_4,9",
        "west"      :DES+"desert_3,8"
             ]));
}
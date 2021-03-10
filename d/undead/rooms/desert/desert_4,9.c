#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,9",
        "east"      :DES+"desert_4,10",
        "south"     :DES+"desert_5,9",
        "west"      :DES+"desert_4,8"
             ]));
}
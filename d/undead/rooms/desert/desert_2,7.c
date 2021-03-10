#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,7",
        "east"      :DES+"desert_2,8",
        "south"     :DES+"desert_3,7",
        "west"      :DES+"desert_2,6"
             ]));
}
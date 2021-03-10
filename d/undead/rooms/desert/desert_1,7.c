#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,7",
        "east"      :DES+"desert_1,8",
        "south"     :DES+"desert_2,7",
        "west"      :DES+"desert_1,6"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,7",
        "east"      :DES+"desert_3,8",
        "south"     :DES+"desert_4,7",
        "west"      :DES+"desert_3,6"
             ]));
}
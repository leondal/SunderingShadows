#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,7",
        "east"      :DES+"desert_4,8",
        "south"     :DES+"desert_5,7",
        "west"      :DES+"desert_4,6"
             ]));
}
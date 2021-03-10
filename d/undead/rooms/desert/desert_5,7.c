#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,7",
        "east"      :DES+"desert_5,8",
        "south"     :DES+"desert_6,7",
        "west"      :DES+"desert_5,6"
             ]));
}
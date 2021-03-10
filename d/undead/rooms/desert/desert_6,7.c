#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,7",
        "east"      :DES+"desert_6,8",
        "south"     :DES+"desert_7,7",
        "west"      :DES+"desert_6,6"
             ]));
}
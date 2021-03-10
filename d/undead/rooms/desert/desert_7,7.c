#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,7",
        "east"      :DES+"desert_7,8",
        "south"     :DES+"desert_8,7",
        "west"      :DES+"desert_7,6"
             ]));
}
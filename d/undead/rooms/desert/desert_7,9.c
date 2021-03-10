#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,9",
        "east"      :DES+"desert_7,10",
        "south"     :DES+"desert_8,9",
        "west"      :DES+"desert_7,8"
             ]));
}
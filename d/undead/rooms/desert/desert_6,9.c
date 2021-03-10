#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,9",
        "east"      :DES+"desert_6,10",
        "south"     :DES+"desert_7,9",
        "west"      :DES+"desert_6,8"
             ]));
}
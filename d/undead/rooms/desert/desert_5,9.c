#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,9",
        "east"      :DES+"desert_5,10",
        "south"     :DES+"desert_6,9",
        "west"      :DES+"desert_5,8"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,8",
        "east"      :DES+"desert_1,9",
        "south"     :DES+"desert_2,8",
        "west"      :DES+"desert_1,7"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,8",
        "east"      :DES+"desert_2,9",
        "south"     :DES+"desert_3,8",
        "west"      :DES+"desert_2,7"
             ]));
}
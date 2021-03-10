#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,8",
        "east"      :DES+"desert_3,9",
        "south"     :DES+"desert_4,8",
        "west"      :DES+"desert_3,7"
             ]));
}
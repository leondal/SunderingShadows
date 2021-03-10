#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,8",
        "east"      :DES+"desert_4,9",
        "south"     :DES+"desert_5,8",
        "west"      :DES+"desert_4,7"
             ]));
}
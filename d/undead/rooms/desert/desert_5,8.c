#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,8",
        "east"      :DES+"desert_5,9",
        "south"     :DES+"desert_6,8",
        "west"      :DES+"desert_5,7"
             ]));
}
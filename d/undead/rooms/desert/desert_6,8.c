#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,8",
        "east"      :DES+"desert_6,9",
        "south"     :DES+"desert_7,8",
        "west"      :DES+"desert_6,7"
             ]));
}
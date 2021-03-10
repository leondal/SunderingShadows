#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,8",
        "east"      :DES+"desert_7,9",
        "south"     :DES+"desert_8,8",
        "west"      :DES+"desert_7,7"
             ]));
}
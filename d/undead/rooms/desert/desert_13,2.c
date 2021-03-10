#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,2",
        "east"      :DES+"desert_13,3",
        "south"     :DES+"desert_14,2",
        "west"      :DES+"desert_13,1"
             ]));
}
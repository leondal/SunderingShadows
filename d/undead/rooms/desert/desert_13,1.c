#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,1",
        "east"      :DES+"desert_13,2",
        "south"     :DES+"desert_14,1",
        "west"      :DES+"desert_13,0"
             ]));
}
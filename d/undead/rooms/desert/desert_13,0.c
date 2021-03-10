#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,0",
        "east"      :DES+"desert_13,1",
        "south"     :DES+"desert_14,0"
             ]));
}
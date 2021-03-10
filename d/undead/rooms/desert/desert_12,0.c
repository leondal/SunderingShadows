#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,0",
        "east"      :DES+"desert_12,1",
        "south"     :DES+"desert_13,0"
             ]));
}
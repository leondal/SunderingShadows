#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,0",
        "east"      :DES+"desert_11,1",
        "south"     :DES+"desert_12,0"
             ]));
}
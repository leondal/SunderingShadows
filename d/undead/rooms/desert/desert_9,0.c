#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,0",
        "east"      :DES+"desert_9,1",
        "south"     :DES+"desert_10,0"
             ]));
}
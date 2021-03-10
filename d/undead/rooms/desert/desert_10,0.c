#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,0",
        "east"      :DES+"desert_10,1",
        "south"     :DES+"desert_11,0"
             ]));
}
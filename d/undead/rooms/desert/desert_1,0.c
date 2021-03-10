#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,0",
        "east"      :DES+"desert_1,1",
        "south"     :DES+"desert_2,0"
             ]));
}
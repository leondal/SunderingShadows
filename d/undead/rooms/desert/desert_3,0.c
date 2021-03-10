#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,0",
        "east"      :DES+"desert_3,1",
        "south"     :DES+"desert_4,0"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,0",
        "east"      :DES+"desert_5,1",
        "south"     :DES+"desert_6,0"
             ]));
}
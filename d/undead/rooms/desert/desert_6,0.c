#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,0",
        "east"      :DES+"desert_6,1",
        "south"     :DES+"desert_7,0"
             ]));
}
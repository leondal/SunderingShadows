#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,1",
        "east"      :DES+"desert_8,2",
        "south"     :DES+"desert_9,1",
        "west"      :DES+"desert_8,0"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,1",
        "east"      :DES+"desert_9,2",
        "south"     :DES+"desert_10,1",
        "west"      :DES+"desert_9,0"
             ]));
}
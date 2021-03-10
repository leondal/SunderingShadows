#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,1",
        "east"      :DES+"desert_10,2",
        "south"     :DES+"desert_11,1",
        "west"      :DES+"desert_10,0"
             ]));
}
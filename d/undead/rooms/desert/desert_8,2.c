#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,2",
        "east"      :DES+"desert_8,3",
        "south"     :DES+"desert_9,2",
        "west"      :DES+"desert_8,1"
             ]));
}
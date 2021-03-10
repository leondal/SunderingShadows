#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,2",
        "east"      :DES+"desert_9,3",
        "south"     :DES+"desert_10,2",
        "west"      :DES+"desert_9,1"
             ]));
}
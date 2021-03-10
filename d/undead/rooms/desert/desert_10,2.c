#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,2",
        "east"      :DES+"desert_10,3",
        "south"     :DES+"desert_11,2",
        "west"      :DES+"desert_10,1"
             ]));
}
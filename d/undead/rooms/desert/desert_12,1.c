#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,1",
        "east"      :DES+"desert_12,2",
        "south"     :DES+"desert_13,1",
        "west"      :DES+"desert_12,0"
             ]));
}
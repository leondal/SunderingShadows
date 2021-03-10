#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,1",
        "east"      :DES+"desert_11,2",
        "south"     :DES+"desert_12,1",
        "west"      :DES+"desert_11,0"
             ]));
}
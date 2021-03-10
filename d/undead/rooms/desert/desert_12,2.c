#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,2",
        "east"      :DES+"desert_12,3",
        "south"     :DES+"desert_13,2",
        "west"      :DES+"desert_12,1"
             ]));
}
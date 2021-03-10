#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,2",
        "east"      :DES+"desert_11,3",
        "south"     :DES+"desert_12,2",
        "west"      :DES+"desert_11,1"
             ]));
}
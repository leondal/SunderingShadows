#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,2",
        "east"      :DES+"desert_1,3",
        "south"     :DES+"desert_2,2",
        "west"      :DES+"desert_1,1"
             ]));
}
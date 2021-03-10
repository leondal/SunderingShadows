#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,1",
        "east"      :DES+"desert_1,2",
        "south"     :DES+"desert_2,1",
        "west"      :DES+"desert_1,0"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,1",
        "east"      :DES+"desert_2,2",
        "south"     :DES+"desert_3,1",
        "west"      :DES+"desert_2,0"
             ]));
}
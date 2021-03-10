#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,1",
        "east"      :DES+"desert_3,2",
        "south"     :DES+"desert_4,1",
        "west"      :DES+"desert_3,0"
             ]));
}
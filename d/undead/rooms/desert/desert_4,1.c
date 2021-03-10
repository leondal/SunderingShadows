#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,1",
        "east"      :DES+"desert_4,2",
        "south"     :DES+"desert_5,1",
        "west"      :DES+"desert_4,0"
             ]));
}
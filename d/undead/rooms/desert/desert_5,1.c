#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,1",
        "east"      :DES+"desert_5,2",
        "south"     :DES+"desert_6,1",
        "west"      :DES+"desert_5,0"
             ]));
}
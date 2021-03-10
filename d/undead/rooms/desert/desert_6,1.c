#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,1",
        "east"      :DES+"desert_6,2",
        "south"     :DES+"desert_7,1",
        "west"      :DES+"desert_6,0"
             ]));
}
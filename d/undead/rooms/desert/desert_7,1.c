#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,1",
        "east"      :DES+"desert_7,2",
        "south"     :DES+"desert_8,1",
        "west"      :DES+"desert_7,0"
             ]));
}
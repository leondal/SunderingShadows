#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,2",
        "east"      :DES+"desert_6,3",
        "south"     :DES+"desert_7,2",
        "west"      :DES+"desert_6,1"
             ]));
}
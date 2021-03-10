#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,2",
        "east"      :DES+"desert_4,3",
        "south"     :DES+"desert_5,2",
        "west"      :DES+"desert_4,1"
             ]));
}
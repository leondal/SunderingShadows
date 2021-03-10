#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,2",
        "east"      :DES+"desert_3,3",
        "south"     :DES+"desert_4,2",
        "west"      :DES+"desert_3,1"
             ]));
}
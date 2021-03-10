#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,2",
        "east"      :DES+"desert_5,3",
        "south"     :DES+"desert_6,2",
        "west"      :DES+"desert_5,1"
             ]));
}
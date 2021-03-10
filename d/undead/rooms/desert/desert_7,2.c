#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,2",
        "east"      :DES+"desert_7,3",
        "south"     :DES+"desert_8,2",
        "west"      :DES+"desert_7,1"
             ]));
}
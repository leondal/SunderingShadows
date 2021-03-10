#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,4",
        "east"      :DES+"desert_1,5",
        "south"     :DES+"desert_2,4",
        "west"      :DES+"desert_1,3"
             ]));
}
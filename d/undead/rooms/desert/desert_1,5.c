#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,5",
        "east"      :DES+"desert_1,6",
        "south"     :DES+"desert_2,5",
        "west"      :DES+"desert_1,4"
             ]));
}
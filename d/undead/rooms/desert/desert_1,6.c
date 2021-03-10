#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,6",
        "east"      :DES+"desert_1,7",
        "south"     :DES+"desert_2,6",
        "west"      :DES+"desert_1,5"
             ]));
}
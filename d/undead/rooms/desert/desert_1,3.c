#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_0,3",
        "east"      :DES+"desert_1,4",
        "south"     :DES+"desert_2,3",
        "west"      :DES+"desert_1,2"
             ]));
}
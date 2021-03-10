#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,4",
        "east"      :DES+"desert_2,5",
        "south"     :DES+"desert_3,4",
        "west"      :DES+"desert_2,3"
             ]));
}
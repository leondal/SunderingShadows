#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,5",
        "east"      :DES+"desert_2,6",
        "south"     :DES+"desert_3,5",
        "west"      :DES+"desert_2,4"
             ]));
}
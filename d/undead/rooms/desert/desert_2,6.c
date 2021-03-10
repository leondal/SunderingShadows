#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,6",
        "east"      :DES+"desert_2,7",
        "south"     :DES+"desert_3,6",
        "west"      :DES+"desert_2,5"
             ]));
}
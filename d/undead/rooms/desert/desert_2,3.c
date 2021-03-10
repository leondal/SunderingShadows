#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_1,3",
        "east"      :DES+"desert_2,4",
        "south"     :DES+"desert_3,3",
        "west"      :DES+"desert_2,2"
             ]));
}
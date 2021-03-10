#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,4",
        "east"      :DES+"desert_3,5",
        "south"     :DES+"desert_4,4",
        "west"      :DES+"desert_3,3"
             ]));
}
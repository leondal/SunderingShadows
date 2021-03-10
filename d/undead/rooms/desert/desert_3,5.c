#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,5",
        "east"      :DES+"desert_3,6",
        "south"     :DES+"desert_4,5",
        "west"      :DES+"desert_3,4"
             ]));
}
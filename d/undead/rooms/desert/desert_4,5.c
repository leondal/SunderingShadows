#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,5",
        "east"      :DES+"desert_4,6",
        "south"     :DES+"desert_5,5",
        "west"      :DES+"desert_4,4"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,5",
        "east"      :DES+"desert_8,6",
        "south"     :DES+"desert_9,5",
        "west"      :DES+"desert_8,4"
             ]));
}
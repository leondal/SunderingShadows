#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,6",
        "east"      :DES+"desert_8,7",
        "south"     :DES+"desert_9,6",
        "west"      :DES+"desert_8,5"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,4",
        "east"      :DES+"desert_8,5",
        "south"     :DES+"desert_9,4",
        "west"      :DES+"desert_8,3"
             ]));
}
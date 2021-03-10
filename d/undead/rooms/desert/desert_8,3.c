#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,3",
        "east"      :DES+"desert_8,4",
        "south"     :DES+"desert_9,3",
        "west"      :DES+"desert_8,2"
             ]));
}
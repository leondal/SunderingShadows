#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,4",
        "east"      :DES+"desert_9,5",
        "south"     :DES+"desert_10,4",
        "west"      :DES+"desert_9,3"
             ]));
}
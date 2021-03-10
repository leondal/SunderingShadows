#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,4",
        "east"      :DES+"desert_10,5",
        "south"     :DES+"desert_11,4",
        "west"      :DES+"desert_10,3"
             ]));
}
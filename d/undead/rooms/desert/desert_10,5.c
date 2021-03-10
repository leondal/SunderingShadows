#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,5",
        "east"      :DES+"desert_10,6",
        "south"     :DES+"desert_11,5",
        "west"      :DES+"desert_10,4"
             ]));
}
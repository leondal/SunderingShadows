#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,5",
        "east"      :DES+"desert_9,6",
        "south"     :DES+"desert_10,5",
        "west"      :DES+"desert_9,4"
             ]));
}
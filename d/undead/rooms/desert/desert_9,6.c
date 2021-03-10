#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,6",
        "east"      :DES+"desert_9,7",
        "south"     :DES+"desert_10,6",
        "west"      :DES+"desert_9,5"
             ]));
}
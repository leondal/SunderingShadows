#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,6",
        "east"      :DES+"desert_10,7",
        "south"     :DES+"desert_11,6",
        "west"      :DES+"desert_10,5"
             ]));
}
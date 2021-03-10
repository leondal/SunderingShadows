#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_9,3",
        "east"      :DES+"desert_10,4",
        "south"     :DES+"desert_11,3",
        "west"      :DES+"desert_10,2"
             ]));
}
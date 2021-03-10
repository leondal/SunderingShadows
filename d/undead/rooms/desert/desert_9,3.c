#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_8,3",
        "east"      :DES+"desert_9,4",
        "south"     :DES+"desert_10,3",
        "west"      :DES+"desert_9,2"
             ]));
}
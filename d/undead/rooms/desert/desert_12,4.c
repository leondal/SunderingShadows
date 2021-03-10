#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,4",
        "east"      :DES+"desert_12,5",
        "south"     :DES+"desert_13,4",
        "west"      :DES+"desert_12,3"
             ]));
}
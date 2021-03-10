#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,3",
        "east"      :DES+"desert_12,4",
        "south"     :DES+"desert_13,3",
        "west"      :DES+"desert_12,2"
             ]));
}
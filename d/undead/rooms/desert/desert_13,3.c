#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,3",
        "east"      :DES+"desert_13,4",
        "south"     :DES+"desert_14,3",
        "west"      :DES+"desert_13,2"
             ]));
}
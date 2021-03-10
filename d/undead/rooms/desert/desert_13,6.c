#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,6",
        "east"      :DES+"desert_13,7",
        "south"     :DES+"desert_14,6",
        "west"      :DES+"desert_13,5"
             ]));
}
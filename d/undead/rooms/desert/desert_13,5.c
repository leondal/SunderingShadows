#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,5",
        "east"      :DES+"desert_13,6",
        "south"     :DES+"desert_14,5",
        "west"      :DES+"desert_13,4"
             ]));
}
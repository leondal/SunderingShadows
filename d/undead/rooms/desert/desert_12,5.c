#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,5",
        "east"      :DES+"desert_12,6",
        "south"     :DES+"desert_13,5",
        "west"      :DES+"desert_12,4"
             ]));
}
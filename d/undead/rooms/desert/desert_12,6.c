#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_11,6",
        "east"      :DES+"desert_12,7",
        "south"     :DES+"desert_13,6",
        "west"      :DES+"desert_12,5"
             ]));
}
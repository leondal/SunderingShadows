#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,5",
        "east"      :DES+"desert_11,6",
        "south"     :DES+"desert_12,5",
        "west"      :DES+"desert_11,4"
             ]));
}
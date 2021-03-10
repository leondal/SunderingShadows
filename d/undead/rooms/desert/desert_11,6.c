#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,6",
        "east"      :DES+"desert_11,7",
        "south"     :DES+"desert_12,6",
        "west"      :DES+"desert_11,5"
             ]));
}
#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,4",
        "east"      :DES+"desert_11,5",
        "south"     :DES+"desert_12,4",
        "west"      :DES+"desert_11,3"
             ]));
}
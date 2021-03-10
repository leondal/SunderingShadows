#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,3",
        "east"      :DES+"desert_11,4",
        "south"     :DES+"desert_12,3",
        "west"      :DES+"desert_11,2"
             ]));
}
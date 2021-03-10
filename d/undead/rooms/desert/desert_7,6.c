#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,6",
        "east"      :DES+"desert_7,7",
        "south"     :DES+"desert_8,6",
        "west"      :DES+"desert_7,5"
             ]));
}
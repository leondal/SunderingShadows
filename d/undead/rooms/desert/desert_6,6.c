#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,6",
        "east"      :DES+"desert_6,7",
        "south"     :DES+"desert_7,6",
        "west"      :DES+"desert_6,5"
             ]));
}
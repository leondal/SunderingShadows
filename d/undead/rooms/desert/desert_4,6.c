#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,6",
        "east"      :DES+"desert_4,7",
        "south"     :DES+"desert_5,6",
        "west"      :DES+"desert_4,5"
             ]));
}
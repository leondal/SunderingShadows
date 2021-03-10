#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_2,6",
        "east"      :DES+"desert_3,7",
        "south"     :DES+"desert_4,6",
        "west"      :DES+"desert_3,5"
             ]));
}
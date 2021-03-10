#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_3,4",
        "east"      :DES+"desert_4,5",
        "south"     :DES+"desert_5,4",
        "west"      :DES+"desert_4,3"
             ]));
}
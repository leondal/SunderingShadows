#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,5",
        "east"      :DES+"desert_6,6",
        "south"     :DES+"desert_7,5",
        "west"      :DES+"desert_6,4"
             ]));
}
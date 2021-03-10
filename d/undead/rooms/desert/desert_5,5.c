#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,5",
        "east"      :DES+"desert_5,6",
        "south"     :DES+"desert_6,5",
        "west"      :DES+"desert_5,4"
             ]));
}
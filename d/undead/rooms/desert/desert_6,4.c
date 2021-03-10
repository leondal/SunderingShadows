#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_5,4",
        "east"      :DES+"desert_6,5",
        "south"     :DES+"desert_7,4",
        "west"      :DES+"desert_6,3"
             ]));
}
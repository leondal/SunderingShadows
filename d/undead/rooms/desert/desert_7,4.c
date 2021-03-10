#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_6,4",
        "east"      :DES+"desert_7,5",
        "south"     :DES+"desert_8,4",
        "west"      :DES+"desert_7,3"
             ]));
}
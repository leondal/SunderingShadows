#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,6",
        "east"      :DES+"desert_5,7",
        "south"     :DES+"desert_6,6",
        "west"      :DES+"desert_5,5"
             ]));
}
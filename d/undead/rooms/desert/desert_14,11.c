#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_13,11",
        "east"      :DES+"desert_14,12",
        "west"      :DES+"desert_14,10"
             ]));
}
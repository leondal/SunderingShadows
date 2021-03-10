#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_13,12",
        "east"      :DES+"desert_14,13",
        "west"      :DES+"desert_14,11"
             ]));
}
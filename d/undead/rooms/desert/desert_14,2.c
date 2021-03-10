#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_13,2",
        "east"      :DES+"desert_14,3",
        "west"      :DES+"desert_14,1"
             ]));
}
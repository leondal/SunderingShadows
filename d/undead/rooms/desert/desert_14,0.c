#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_13,0",
        "east"      :DES+"desert_14,1"
             ]));
}
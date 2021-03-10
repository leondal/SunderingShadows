#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_13,9",
        "east"      :DES+"desert_14,10",
        "west"      :DES+"desert_14,8"
             ]));
}
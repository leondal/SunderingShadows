#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_13,6",
        "east"      :DES+"desert_14,7",
        "west"      :DES+"desert_14,5"
             ]));
}
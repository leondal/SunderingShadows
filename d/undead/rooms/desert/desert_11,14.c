#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_10,14",
        "south"     :DES+"desert_12,14",
        "west"      :DES+"desert_11,13"
             ]));
}
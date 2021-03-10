#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_4,14",
        "south"     :DES+"desert_6,14",
        "west"      :DES+"desert_5,13"
             ]));
}
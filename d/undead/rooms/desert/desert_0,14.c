#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :DES+"desert_1,14",
        "west"      :DES+"desert_0,13"
             ]));
}
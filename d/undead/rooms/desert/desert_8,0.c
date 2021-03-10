#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_7,0",
        "east"      :DES+"desert_8,1",
        "south"     :DES+"desert_9,0",
        "west"      :BO+"bridge"
             ]));
}
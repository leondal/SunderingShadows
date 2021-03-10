#include "../../undead.h"

inherit INH+"tomb_one.c";

void place_tomb();

void create() 
{
    ::create();

    set_exits(([
        "north"     :HALL+"temproad2",
             ]));
    set_no_clean(1);
    
}
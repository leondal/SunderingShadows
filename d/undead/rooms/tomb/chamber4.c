#include <std.h>
#include "../../undead.h"

inherit INH+"tomb_five.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :HALL+"hall10"
             ]));

}

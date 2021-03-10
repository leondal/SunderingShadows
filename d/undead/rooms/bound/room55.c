#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room56",
        "west"      :BO+"room54"
             ]));

}

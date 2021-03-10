#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BO+"room50",
        "south"     :BO+"room52"
             ]));

}

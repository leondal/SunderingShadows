#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room50",
        "east"      :BO+"room52",
        "west"      :BO+"room18"
             ]));

}

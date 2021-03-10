#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room13",
        "east"      :BO+"room15",
        "west"      :BO+"room21"
             ]));

}

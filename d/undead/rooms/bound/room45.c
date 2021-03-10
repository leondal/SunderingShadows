#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room41",
        "east"      :BO+"room46",
        "south"     :BO+"room48",
        "west"      :BO+"room31"
             ]));

}

#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"room42",
        "south"     :BO+"room45",
        "west"      :BO+"room40"
             ]));

}

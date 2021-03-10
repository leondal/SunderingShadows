#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room40",
        "east"      :BO+"room45",
        "west"      :BO+"room33",
        "south"     :BO+"room2"
             ]));

}

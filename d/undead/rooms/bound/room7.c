#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room41",
        "east"      :PATH+"room53",
        "south"     :BO+"room8",
        "west"      :BO+"room6"
             ]));

}

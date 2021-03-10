#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room4",
        "east"      :PATH+"room41",
        "south"     :BO+"room6",
        "west"      :BF+"room39"
             ]));

}

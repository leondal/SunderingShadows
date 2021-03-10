#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom5",
        "east"      :BO+"sroom3",
        "west"      :PATH+"room28"
             ]));

}

#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :PATH+"room70",
        "east"      :BO+"sroom25",
        "south"     :BO+"sroom28"
             ]));

}

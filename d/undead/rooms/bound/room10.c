#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :PATH+"room63",
        "north"     :BO+"room9",
        "east"      :BO+"room11",
        "south"     :BO+"room23",
        "west"      :BO+"room26"
             ]));

}

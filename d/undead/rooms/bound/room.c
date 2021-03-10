#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();
 
    set_exits(([
        "north"     :BO+"room48",
        "east"      :PATH+"room19",
        "south"     :PATH+"room29",
        "west"      :BO+"room3"
             ]));

}

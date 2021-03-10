#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room72",
        "northeast" :PATH+"room73",
        "east"      :PATH+"room78"
             ]));

}

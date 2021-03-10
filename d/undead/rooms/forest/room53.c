#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "meadow"    :BO+"room7",
        "northeast" :PATH+"room43",
        "east"      :PATH+"room54"
             ]));

}


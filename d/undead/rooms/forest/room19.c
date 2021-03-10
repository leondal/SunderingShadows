#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "meadow"    :BO+"room",
        "east"      :PATH+"room20"
             ]));

}


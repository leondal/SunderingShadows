#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "hill"      :BO+"room5",
        "north"     :PATH+"room29",
        "meadow"    :BO+"room7",
        "east"      :PATH+"room42"
             ]));

}


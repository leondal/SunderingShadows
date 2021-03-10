#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "meadow"    :BO+"room",
        "south"     :PATH+"room41",
        "east"      :PATH+"room30",
        "hill"      :BO+"room4"
             ]));

}

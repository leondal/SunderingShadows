#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :PATH+"room62",
        "south"     :PATH+"room70",
        "west"      :PATH+"room60"
             ]));

}

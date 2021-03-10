#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :PATH+"room46",
        "west"      :PATH+"room44",
        "south"     :PATH+"room56"
             ]));

}

#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :PATH+"room4",
        "southeast" :PATH+"room18",
        "south"     :PATH+"room17",
        "west"      :PATH+"room9"
             ]));

}

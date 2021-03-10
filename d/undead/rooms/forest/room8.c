#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room3",
        "northeast" :PATH+"room4",
        "east"      :PATH+"room9",
        "south"     :PATH+"room15",
        "west"      :PATH+"room7"
             ]));

}

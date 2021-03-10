#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :PATH+"room26",
        "west"      :PATH+"room24",
        "northeast" :PATH+"room17"
             ]));

}

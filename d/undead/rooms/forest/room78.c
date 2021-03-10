#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :PATH+"room74",
        "east"      :PATH+"room79",
        "west"      :PATH+"room77"
             ]));

}

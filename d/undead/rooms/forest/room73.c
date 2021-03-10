#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room66",
        "east"      :PATH+"room74",
        "southwest" :PATH+"room77",
        "west"      :PATH+"room72"
             ]));

}

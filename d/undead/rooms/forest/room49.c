#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :PATH+"room36",
        "east"      :PATH+"room50",
        "south"     :PATH+"room60",
        "southwest" :PATH+"room59",
        "west"      :PATH+"room48"
             ]));

}

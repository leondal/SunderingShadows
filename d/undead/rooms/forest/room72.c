#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room65",
        "northeast" :PATH+"room66",
        "east"      :PATH+"room73",
        "south"     :PATH+"room77",
        "west"      :PATH+"room71"
             ]));

}

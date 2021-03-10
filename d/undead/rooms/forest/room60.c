#include "../../undead.h"

inherit INH+"forest_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room49",
        "east"      :PATH+"room61",
        "west"      :PATH+"room59"
             ]));

}

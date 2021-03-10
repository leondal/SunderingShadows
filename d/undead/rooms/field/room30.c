#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room29",
        "east"      :BF+"room36",
        "west"      :BF+"room24"
             ]));

}

#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room20",
        "east"      :BF+"room29",
        "south"     :BF+"room24",
        "west"      :BF+"room18"
             ]));

}
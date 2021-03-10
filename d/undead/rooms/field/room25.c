#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room19",
        "east"      :BF+"room37",
        "west"      :BF+"room12"
             ]));

}
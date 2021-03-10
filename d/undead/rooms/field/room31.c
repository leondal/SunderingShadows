#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BF+"room22",
        "south"     :BF+"room23"
             ]));

}
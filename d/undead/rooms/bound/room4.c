#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room3",
        "south"     :BO+"room5",
        "west"      :BF+"room38",
        "east"      :PATH+"room29"
             ]));

}

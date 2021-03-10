#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :PATH+"room",
        "west"      :BO+"room43"
             ]));

}

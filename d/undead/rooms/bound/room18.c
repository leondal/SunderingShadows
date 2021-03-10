#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :PATH+"room80",
        "east"      :BO+"room19",
        "west"      :BO+"room17"
             ]));

}

#include "../../undead.h"

inherit INH+"bound_four.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room43",
        "east"      :PATH+"room5",
        "west"      :BO+"room46"
             ]));

}

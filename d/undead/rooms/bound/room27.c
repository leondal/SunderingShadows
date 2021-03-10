#include "../../undead.h"

inherit INH+"bound_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"room28",
        "east"      :BO+"room26",
        "west"      :BO+"room29"
             ]));

}

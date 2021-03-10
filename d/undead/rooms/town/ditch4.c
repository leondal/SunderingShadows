#include "../../undead.h"

inherit INH+"town_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"ditch5",
        "south"     :TOWN+"ditch3"
             ]));

}

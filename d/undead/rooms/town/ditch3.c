#include "../../undead.h"

inherit INH+"town_six.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :TOWN+"ditch4",
        "west"      :TOWN+"ditch2"
             ]));

}

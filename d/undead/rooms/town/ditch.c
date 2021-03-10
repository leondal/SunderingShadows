#include "../../undead.h"

inherit INH+"town_six.c";

void create() 
{
    ::create();

    set_exits(([
        "up"        :TOWN+"street8",
        "east"      :TOWN+"ditch2"
             ]));

}

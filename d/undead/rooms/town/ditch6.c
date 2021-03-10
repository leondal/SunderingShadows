#include "../../undead.h"

inherit INH+"town_six.c";

void create() 
{
    ::create();

    set_exits(([
        "up"        :BO+"path38",
        "south"     :TOWN+"ditch5"
             ]));

}

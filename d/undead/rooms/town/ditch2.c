#include "../../undead.h"

inherit INH+"town_six.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :TOWN+"ditch3",
        "west"      :TOWN+"ditch"
             ]));

}

#include <std.h>
#include "../../undead.h"

inherit INH+"tomb_five.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :HALL+"hall9"
             ]));

}

void reset() 
{
    ::reset();

    if(!present("ghoul"))
    {
        new(MON"ghoul")->move(TO);
        new(MON"ghoul")->move(TO);
    }
}

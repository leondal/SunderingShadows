#include <std.h>
#include "../drownew.h"

inherit CAVERN;

void create()
{
    ::create();
    set_exits(([
    "north" : DNROOMS+"dn12",
    "northeast" : DNROOMS+"dn13",
    "east" : DNROOMS+"dn16",
    "southeast" : DNROOMS+"dn19",
    "northwest" : DNROOMS+"dn11"
    ]));
}

void reset()
{
    ::reset();
    if(!present("snark", TO))
    {
        new(DNMONS+"kobold_leader")->move(TO);
    }
    return;
}
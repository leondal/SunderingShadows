//was bugging on an illegal index when it hit the chance for a demon
//per Garrett's suggestion, generating the amazons from a call so the
//demon's init can finish before the others - Styx 1/19/02

#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "north" : FRPATH "forest8",
        "southeast" : FRPATH "forest6",
    ]));
}
void reset()
{
    ::reset();
}


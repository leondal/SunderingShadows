#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh26",
    "east": MRPATH "marsh20",
    "west": MRPATH "marsh18",
    "south": MRPATH "marsh7",
    ]) );
}


#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh18",
    "east": MRPATH "marsh7",
    "west": MRPATH "marsh9",
    "south": MRPATH "marsh5",
    ]) );
}


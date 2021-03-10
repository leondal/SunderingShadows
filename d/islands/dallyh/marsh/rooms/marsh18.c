#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"north": MRPATH "marsh16",
    "east": MRPATH "marsh19",
    "west": MRPATH "marsh10",
    "south": MRPATH "marsh8",
    ]) );
}


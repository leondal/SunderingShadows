#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh19",
    //"east": MRPATH "marsh6",
    "west": MRPATH "marsh8",
    "south": MRPATH "marsh6",
    ]) );
}


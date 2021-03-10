#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh7",
    //"east": MRPATH "marsh6",
    "west": MRPATH "marsh5",
    "south": MRPATH "marsh2",
    ]) );
}


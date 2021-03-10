#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh8",
    "east": MRPATH "marsh6",
    "west": MRPATH "marsh4",
    //"north": RPATH "marsh200",
    ]) );
}


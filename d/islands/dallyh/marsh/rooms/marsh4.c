#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh9",
    "east": MRPATH "marsh5",
    "south": MRPATH "marsh3",
    //"north": RPATH "marsh200",
    ]) );
}


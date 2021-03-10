#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh10",
    "east": MRPATH "marsh8",
    //"west": MRPATH "marsh9",
    "south": MRPATH "marsh4",
    ]) );
}


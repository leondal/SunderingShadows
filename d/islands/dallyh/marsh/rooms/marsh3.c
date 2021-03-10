#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh4",
    "southeast": MRPATH "marshenter",
    //"south": RPATH "marshenter",
    //"north": RPATH "marsh200",
    ]) );
}


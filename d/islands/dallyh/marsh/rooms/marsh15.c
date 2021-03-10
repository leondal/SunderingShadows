#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh13",
    //"east": MRPATH "marsh11",
    //"west": MRPATH "marsh13",
    "southeast": MRPATH "marsh16",
    ]) );
}


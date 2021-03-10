#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"north": MRPATH "marsh14",
    //"east": MRPATH "marsh11",
    //"west": MRPATH "marsh13",
    "south": MRPATH "marsh13",
    ]) );
}


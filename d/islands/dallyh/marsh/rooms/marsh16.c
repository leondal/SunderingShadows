#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["northwest": MRPATH "marsh15",
    //"east": MRPATH "marsh11",
    //"west": MRPATH "marsh13",
    "south": MRPATH "marsh17",
    ]) );
}


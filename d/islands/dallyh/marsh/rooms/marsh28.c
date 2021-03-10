#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["northwest": MRPATH "marsh29",
    //"southeast": MRPATH "marsh23",
    //"southwest": MRPATH "marsh24",
    "south": MRPATH "marsh27",
    ]) );
}


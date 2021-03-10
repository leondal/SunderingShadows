#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh28",
    //"southeast": MRPATH "marsh23",
    //"southwest": MRPATH "marsh24",
    "south": MRPATH "marsh26",
    ]) );
}


#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"northeast": MRPATH "marsh24",
    //"southeast": MRPATH "marsh23",
    "northwest": MRPATH "marsh22",
    //"south": MRPATH "marsh7",
    ]) );
}


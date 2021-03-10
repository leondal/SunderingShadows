#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["northeast": MRPATH "marsh24",
    "southeast": MRPATH "marsh22",
    "west": MRPATH "marsh20",
    //"south": MRPATH "marsh7",
    ]) );
}


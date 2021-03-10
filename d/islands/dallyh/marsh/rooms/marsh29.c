#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["north": MRPATH "marsh30",
    "southeast": MRPATH "marsh28",
    "west": MRPATH "marsh36",
    //"south": MRPATH "marsh27",
    ]) );
}


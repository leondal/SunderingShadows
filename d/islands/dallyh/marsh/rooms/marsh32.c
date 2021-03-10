#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"northeast": MRPATH "marsh31",
    "east": MRPATH "marsh33",
    "west": MRPATH "marsh31",
    //"south": MRPATH "marsh29",
    ]) );
}


#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"north": MRPATH "marsh26",
    "east": MRPATH "marsh21",
    "west": MRPATH "marsh19",
    //"south": MRPATH "marsh7",
    ]) );
}


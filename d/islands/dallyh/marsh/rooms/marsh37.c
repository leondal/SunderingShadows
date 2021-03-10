#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"north": MRPATH "marsh35",
    "east": MRPATH "marsh36",
    "west": MRPATH "marsh38",
    //"south": MRPATH "marsh34",
    ]) );
}


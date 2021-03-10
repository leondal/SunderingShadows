#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"north": MRPATH "marsh35",
    "east": MRPATH "marsh29",
    "west": MRPATH "marsh37",
    //"south": MRPATH "marsh34",
    ]) );
}


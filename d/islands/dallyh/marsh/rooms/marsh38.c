#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["northwest": MRPATH "marsh39",
    "east": MRPATH "marsh37",
    //"west": MRPATH "marsh38",
    //"south": MRPATH "marsh34",
    ]) );
}


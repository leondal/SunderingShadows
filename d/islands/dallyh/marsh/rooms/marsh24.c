#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( (["northeast": MRPATH "marsh25",
    //"southeast": MRPATH "marsh23",
    "southwest": MRPATH "marsh21",
    //"south": MRPATH "marsh7",
    ]) );
}


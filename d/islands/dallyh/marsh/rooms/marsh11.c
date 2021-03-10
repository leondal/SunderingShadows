#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"northwest": MRPATH "marsh11",
    "southeast": MRPATH "marsh10",
    "west": MRPATH "marsh12",
    //"south": MRPATH "marsh9",
    ]) );
}


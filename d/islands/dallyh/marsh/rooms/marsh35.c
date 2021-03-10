#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DMARSH;

void create()
{
    ::create();
    set_exits( ([//"north": MRPATH "marsh35",
    //"east": MRPATH "marsh33",
    //"west": MRPATH "marsh32",
    "south": MRPATH "marsh34",
    ]) );
}


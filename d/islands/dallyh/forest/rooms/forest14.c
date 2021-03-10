#include "/d/islands/dallyh/ways.h"
#include "/d/islands/dallyh/fways.h"
inherit DFOREST;

void create(){
    ::create();
    set_exits(([
        "southwest" : FRPATH "forest13",
    ]));
}

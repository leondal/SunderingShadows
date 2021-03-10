#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
    "north" : FRPATH "for2",
    "south" : "/d/shadow/virtual/sea/dallyh.dock",
    ]));
}

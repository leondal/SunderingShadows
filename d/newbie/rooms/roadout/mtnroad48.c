//mtnroad48.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south1";

void create(){
   ::create();
   set_long(::query_long()+"  %^GREEN%^Another path breaks away from "+
      "this one, leading to a %^ORANGE%^hut %^GREEN%^to the east.\n");
   set_exits(([
       "west":ROADOUT"mtnroad47",
       "southeast":ROADOUT"mtnroad49",
       "east" : "/d/shadow/room/ekibi/room/p1"
   ]));
}

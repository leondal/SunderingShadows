//mtnroad2.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north1";

void create(){
   ::create();
   set_exits(([
       "north":ROADOUT"mtnroad1",
       "south":ROADOUT"mtnroad3",
   ]));
}

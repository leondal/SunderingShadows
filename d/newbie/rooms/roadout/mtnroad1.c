//mtnroad1.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north1";

void create(){
   ::create();
   set_exits(([
       "north":ROAD"road27",
       "south":ROADOUT"mtnroad2",
   ]));
}

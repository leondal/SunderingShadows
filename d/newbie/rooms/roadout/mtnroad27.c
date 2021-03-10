//mtnroad27.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_middle";

void create(){
   ::create();
   set_exits(([
       "southwest":ROADOUT"mtnroad26",
       "east":ROADOUT"mtnroad28",
   ]));
}

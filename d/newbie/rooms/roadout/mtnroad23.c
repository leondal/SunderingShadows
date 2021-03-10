//mtnroad23.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north2";

void create(){
   ::create();
   set_exits(([
       "north":ROADOUT"mtnroad22",
       "southeast":ROADOUT"mtnroad24",
   ]));
}

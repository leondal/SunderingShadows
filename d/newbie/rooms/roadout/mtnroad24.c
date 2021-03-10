//mtnroad24.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_middle";

void create(){
   ::create();
   set_exits(([
       "northwest":ROADOUT"mtnroad23",
       "east":ROADOUT"mtnroad25",
   ]));
}

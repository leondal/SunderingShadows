//mtnroad25.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_middle";

void create(){
   ::create();
   set_exits(([
       "west":ROADOUT"mtnroad24",
       "southeast":ROADOUT"mtnroad26",
   ]));
}

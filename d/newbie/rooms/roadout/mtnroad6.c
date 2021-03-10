//mtnroad6.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north1";

void create(){
   ::create();
   set_exits(([
       "northwest":ROADOUT"mtnroad5",
       "southeast":ROADOUT"mtnroad7",
   ]));
}

//mtnroad41.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south1";

void create(){
   ::create();
   set_exits(([
//       "southwest":"/d/darkwood/tabor/room/cartroom",
       "south":ROADOUT"mtnroad42",
   ]));
}

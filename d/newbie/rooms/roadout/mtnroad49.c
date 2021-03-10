//mtnroad49.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south1";

void create(){
   ::create();
   set_exits(([
       "northwest":ROADOUT"mtnroad48",
       "south":"/d/shadow/room/forest/road30",
   ]));
}

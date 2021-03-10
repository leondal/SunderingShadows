//mtnroad44.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south1";

void create(){
   ::create();
   set_exits(([
       "west":ROADOUT"mtnroad43",
       "northeast":ROADOUT"mtnroad45",
   ]));
}

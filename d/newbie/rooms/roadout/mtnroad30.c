//mtnroad30.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_middle";

void create(){
   ::create();
   set_exits(([
       "west":ROADOUT"mtnroad29",
       "southeast":ROADOUT"mtnroad31",
   ]));
}

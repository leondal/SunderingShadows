//mtnroad22.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north2";

void create(){
   ::create();
   set_exits(([
       "west":ROADOUT"mtnroad21",
       "south":ROADOUT"mtnroad23",
   ]));
   set_pre_exit_functions( ({"south"}), ({"GoThroughDoor"}) );
}

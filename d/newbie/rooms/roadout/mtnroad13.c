//mtnroad13.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north2";

void create(){
   ::create();
   set_exits(([
       "north":ROADOUT"mtnroad12",
       "southwest":ROADOUT"mtnroad14",
   ]));
   set_pre_exit_functions( ({"southwest"}), ({"GoThroughDoor"}) );
}

//mtnroad14.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north2";

void create(){
   ::create();
   set_exits(([
       "northeast":ROADOUT"mtnroad13",
       "southeast":ROADOUT"mtnroad15",
   ]));
   set_pre_exit_functions( ({"southeast"}), ({"GoThroughDoor"}) );
}

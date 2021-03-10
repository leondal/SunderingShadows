//mtnroad12.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north2";

void create(){
   ::create();
   set_exits(([
       "northwest":ROADOUT"mtnroad11",
       "south":ROADOUT"mtnroad13",
   ]));
   set_pre_exit_functions( ({"south"}), ({"GoThroughDoor"}) );
}

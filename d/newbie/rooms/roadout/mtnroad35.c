//mtnroad35.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south2";

void create(){
   ::create();
   set_exits(([
       "west":ROADOUT"mtnroad34",
       "southeast":ROADOUT"mtnroad36",
   ]));
   set_pre_exit_functions( ({"southeast"}), ({"GoThroughDoor"}) );
}

//mtnroad32.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south2";

void create(){
   ::create();
   set_exits(([
       "west":ROADOUT"mtnroad31",
       "southeast":ROADOUT"mtnroad33",
   ]));
   set_pre_exit_functions( ({"southeast"}), ({"GoThroughDoor"}) );
}

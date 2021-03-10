//mtnroad20.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north2";

void create(){
   ::create();
   set_exits(([
       "northeast":ROADOUT"mtnroad19",
       "southeast":ROADOUT"mtnroad21",
   ]));
   set_pre_exit_functions( ({"southeast"}), ({"GoThroughDoor"}) );
}

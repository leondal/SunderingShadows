//mtnroad19.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north2";

void create(){
   ::create();
   set_exits(([
       "northeast":ROADOUT"mtnroad18",
       "southwest":ROADOUT"mtnroad20",
   ]));
   set_pre_exit_functions( ({"southwest", "northeast"}), ({"GoThroughDoor", "GoThroughDoor"}) );
}

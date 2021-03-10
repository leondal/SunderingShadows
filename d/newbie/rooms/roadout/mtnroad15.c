//mtnroad15.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_north2";

void create(){
   ::create();
   set_exits(([
       "northwest":ROADOUT"mtnroad14",
       "east":ROADOUT"mtnroad16",
   ]));
   set_pre_exit_functions( ({"east"}), ({"GoThroughDoor"}) );
}

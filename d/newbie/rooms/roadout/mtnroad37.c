//mtnroad37.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south2";

void create(){
   ::create();
   set_exits(([
       "northeast":ROADOUT"mtnroad36",
       "east":ROADOUT"mtnroad38",
   ]));
   set_pre_exit_functions( ({"east"}), ({"GoThroughDoor"}) );
}

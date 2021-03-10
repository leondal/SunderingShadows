//mtnroad33.c - road from Offestry toward Shadow area

#include "../../newbie.h"

inherit ROOMS"inherit/road_out_south2";

void create(){
   ::create();
   set_exits(([
       "northwest":ROADOUT"mtnroad32",
       "southwest":ROADOUT"mtnroad34",
   ]));
   set_pre_exit_functions( ({"southwest"}), ({"GoThroughDoor"}) );
}

//road_out_north2 - inherited file for mountainous part of northern end 
//of road between Offestry & Shadow

#include <std.h>
#include "/d/newbie/newbie.h"

inherit ROOM;

void create(){
	::create();
	set_property("light",3);
// set_property("no teleport",1);
   set_name("Winding mountain pass fall");
	set_terrain(NEW_MOUNTS);
	set_travel(FOOT_PATH);
	set_short("%^GREEN%^Winding mountain path%^RESET%^");
	set_long( (: TO,"ldesc" :) );
	set_smell("default","You catch a whiff of pine scent.");
	set_listen("default","You hear the screeching of birds hunting small prey.");
	set_items( ([ 
	"foothills":"%^GREEN%^The foothills seem to be the leading edge of the mountain range.", 
	"roots":"%^ORANGE%^The exposed roots of the trees and bushes that grow along the path.", 
	"path":"%^ORANGE%^The path is well-defined but difficult to traverse safely.", 
	({"mountains", "mountain range"}):"The mountains are even more imposing and "
	"daunting as you struggle along the treacherous path.",
   "shale":"%^BOLD%^%^BLACK%^Thin sheets of the shale often break loose and "
   "slip under foot.",
	]) );
	set_exits(([
       "north": "/d/newbie/rooms/roadout/mtnroad21",
   ]));
   set_pre_exit_functions( ({"north"}), ({"GoThroughDoor"}) );
}

int GoThroughDoor() {
	if(!userp(TP)) return 1;
	if(avatarp(TP) && TP->query_invis()) return 1;
	if(!random(4)) {
	  tell_room(ETP,TPQCN+" slips on a patch of shale that breaks loose.", TP);
	  tell_room(TP,"A layer of the shale breaks loose under your weight and you "
      "slip backwards!\n"
	  "%^ORANGE%^You manage to avoid falling far, but are banged and bruised from"
	  " the fall.");
     TP->do_damage("torso",random(6)+3);
     return 0;
   }
   return 1;
}	

string ldesc(string str) {
  return("%^GREEN%^Winding mountain path%^RESET%^\n"
    "This path winds along the side of the mountains going up, down, and "
    "around where ever a passable area can be found.  Generally it seems "
    "to run southeast to a peak and northwest down the mountain to foothills.  "
    "The path is mostly hard-packed dirt but there are patches of "
    "%^BOLD%^%^BLACK%^loose shale%^RESET%^.  That and frequently exposed roots "
    "where it has eroded make footing difficult at best.  However, in places "
    "it is so steep that you find it easier to climb on hands and knees than "
    "try to walk upright and the roots make good handholds.");
}

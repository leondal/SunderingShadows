//road_out_south2 - inherited file for mountainous section of southern end of road between Offestry & Shadow

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
	::create();
	set_property("light",3);
// set_property("no teleport",1);
   set_name("Rugged mountain pass");
	set_short("%^CYAN%^Rugged mountain pass%^RESET%^");
	set_terrain(NEW_MOUNTS);
	set_travel(FOOT_PATH);
	set_long( (: TO,"ldesc" :) );
	set_smell("default","You catch a scent of pine in the thin mountain air.");
	set_listen("default","You hear dislodged rocks tumbling down the mountainside.");
	set_items( ([ 
	({"trees","pine trees"}):"%^CYAN%^The pine trees are thick enough to provide some cover and block what would probably be a spectacular view.", 
	({"bushes", "scraggly bushes"}):"%^GREEN%^The bushes are generally thorny and often snag your clothing or skin if you try to use them for support.%^RESET%^", 
	({"path", "rocks" }):"%^ORANGE%^The path is littered with rocks that hurt your feet and make footing unstable if you aren't extremely careful." 
	]) );
}

int GoThroughDoor() {
   if(!userp(TP)) return 1;
	if(avatarp(TP) && TP->query_invis()) return 1;
	if(!random(4)) {
	  tell_room(ETP,TPQCN+" gets badly snagged on the thorny bushes.", TP);
	  tell_room(TP,"You get snagged on the thorny bushes as you try to move past.\n"
	  "%^RED%^The thorns make several deep, burning scratches on your exposed skin.");
     TP->do_damage("torso",random(4)+2);
     return 0;
   }
   return 1;
}

string ldesc(string str) {
   return("%^CYAN%^Rugged mountain pass%^RESET%^\n"
     "You are on a winding road crossing over and through a mountainous area "
     "between two large mountain ranges.  The path is steep and covered with "
     "various sizes of loose, sharp-edged rocks as it winds through the only "
     "passable areas of the mountains.  The terrain makes each step a struggle "
     "to keep your balance and avoid tumbling down the steep mountainside.  "
     "Pine trees and scraggly bushes seem to be the only vegetation that can "
     "grow in this rugged terrain.");
}

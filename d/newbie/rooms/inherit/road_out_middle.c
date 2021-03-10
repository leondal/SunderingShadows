//road_out_south2 - mountainous section of southern road between Offestry&Shadow

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
	::create();
	set_property("light",3);
// set_property("no teleport",1);
	set_short("%^BOLD%^%^CYAN%^Top of a mountain peak%^RESET%^");
	set_terrain(NEW_MOUNTS);
	set_travel(FOOT_PATH);
	set_long( (: TO, "ldesc" :) );
	set_smell("default","You smell your own sweat from the strenuous climb.");
	set_listen("default","You hear your own heavy breathing and your heart pounding in the thin air.");
	set_items( ([ 
	({"bushes", "scraggly bushes"}):"%^GREEN%^The bushes are generally thorny and often snag your clothing or skin if you try to use them for support.%^RESET%^", 
	({ "peaks", "peak", "view" }):"%^ORANGE%^The peaks of the mountains to the southeast are so tall they are snow-capped year-round and often obscured by clouds."
	]) );
}

string ldesc(string str) {
  return("%^BOLD%^%^CYAN%^Top of a mountain peak%^RESET%^\n"
    "You have reached the top of a ridge along one of the smaller peaks of this "
    "area.  The footing is still treacherous and the mountain falls away steeply "
    "on both sides here.  Only thorny bushes grow in the nearly solid rock "
    "here.  From this vantage point, you have a spectacular view of the towering "
    "peaks of the Echoes Mountains looming to the southeast.  To the northwest "
    "you can make out traces of what might be a small town.");
}

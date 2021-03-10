//road_out_north1 - inherited file for northern road between Offestry & Shadow

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
	::create();
	set_property("light",3);
// set_property("no teleport",1);
	set_short("%^GREEN%^Path through foothills%^RESET%^");
	set_terrain(NEW_MOUNTS);
	set_travel(FOOT_PATH);
	set_long( (: TO, "ldesc" :) );
	set_smell("default","The air smells moist and clean.");
	set_listen("default","You hear the wind whistling through the trees.");
	set_items( ([ 
	({"foothills", "forested foothills"}):"%^GREEN%^The foothills seem to be the leading edge of the mountain range.", 
	({"trail", "gravel trail" }):"%^BOLD%^Glints of sun shining off the gravel catch your eye and it looks well-maintained.", 
	({"path"}):"%^ORANGE%^The path is comfortably wide and easy to traverse here.", 
	({"range", "mountain range"}):"The mountains look like they will be very difficult and dangerous to cross.",
	]) );
}

string ldesc(string str) {
  return("%^GREEN%^Path through foothills%^RESET%^\n"
    "This path meanders through forested foothills and runs generally north "
    "and south.  To the north you can catch glimpses of a wide gravel trail.  "
    "foreboding mountain range towers to the south but this area seems pretty "
    "much deserted for some reason.");
}

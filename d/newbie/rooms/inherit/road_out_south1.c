//road_out_south1 - inherited file for southern end of road between Offestry & Shadow

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
	::create();
	set_property("light",3);
// set_property("no teleport",1);
	set_short("%^CYAN%^Winding path along the mountain%^RESET%^");
	set_terrain(NEW_MOUNTS);
	set_travel(FOOT_PATH);
	set_long( (: TO,"ldesc" :) );
	set_smell("default","You smell the musty damp leaves and rich soil.");
	set_listen("default","You hear the wind whistling through the trees.");
	set_items( ([ 
	({"trees","pine trees"}):"%^CYAN%^The pine trees are tall and sway in the wind as they compete with the deciduous trees for sunlight.", 
	({"leaves", "pine needles" }):"%^ORANGE%^The fallen leaves and pine needles are brown and decaying.", 
	({"path"}):"%^ORANGE%^The path is comfortably wide and easy to traverse here." 
	]) );
}

string ldesc(string str) {
   return("%^CYAN%^Winding path along the mountain%^RESET%^\n"
     "This winding path along the southern mountainside seems to travel "
     "generally east/west.  You can get glimpses of a pass to the west that "
     "might allow passage through the mountains to the north.  It appears to "
     "have been made by animals and widened out by human travels.  A variety "
     "of trees grow densely here, including several varieties of pines that "
     "provide year-round shade.  Damp fallen leaves and pine needles blanket "
     "the rich soil to cushion your steps.  The path wanders around boulders "
     "and through the undergrowth.");
}

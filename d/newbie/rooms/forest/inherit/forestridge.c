//forestInh3.c - Forest ridges

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_short("%^GREEN%^Forest ridges%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(GAME_TRACK);
   set_long( (: TO, "ldesc" :) );
   set_smell("default","The cedar smell is strong as you brush against the branches.");
   set_listen("default","The thick cedars muffle even the sounds of twigs snapping underfoot.");
   set_items( ([ 
   	"undergrowth":"%^GREEN%^The ivy and ferns are mostly seen down on the hillsides.%^RESET%^", 
	({"hillside", "hillsides"}):"The hillsides are steep and littered with fallen trees covered with vines and other undergrowth.", 
	({"cedars", "trees"}):"%^GREEN%^The cedar trees are thick and bushy.", 
	"ridges":"These ridges provide a vantage point to occasionally see even beyond the passable parts of the forest.",
	"valley":"You can catch a glimpse of a wide gravel trail in the valley generally southward." ]) );
}

string ldesc(string str) {
   return("Ridges have formed here with valleys between them.  With the heavier "
     "undergrowth down in the valleys, the most passable areas are on top of "
     "these various intersecting ridges.  Some areas fall off too steeply to "
     "travel but provide quite a view of the valleys below.  Various types of "
     "trees are scattered along but evergreens are more prevalent in this "
     "area.  Cedars are most common and their thick greenery all year round "
     "blocks the way in many directions.  Their sharp and sticky greenery "
     "scratches any exposed skin as you meander among them.  Decaying trunks of "
     "fallen trees occasionally lie in your path but most are easy enough to "
     "step or climb over.");
}


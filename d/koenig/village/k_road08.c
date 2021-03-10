//k_road08.c - Road through Koenig - coded by Circe 11/15/03
#include <std.h>
#include "../koenig.h"
inherit VILROADS;

void create() {
   ::create();
   set_long(
      "This narrow broken roadway leads through a ransacked village "+
      "that has clearly been abandoned.  Just to the east, a house stands, "+
      "though it can hardly be called such anymore.  There is no door on the "+
      "hinges, and the wood has been charred and blackened.  The windows stand "+
      "empty, allowing the wind to blow soot and ash out into the roadway.  "+
      "Through the northern window, a wooden crib can be seen.  The road continues "+
      "south into the village, or north into the forest pressing close around "+
      "the buildings."+
      "\n");
   add_item("windows","The empty window frames are charred and blackened by "+
      "flames that seem to have climbed up the side of the building.  Strange "+
      "clawmarks also mar the wooden surface.");
   add_item("house","The house is empty, abandoned by the family that once called it "+
      "home.  Strange claw marks and tracks around the doorway suggest that something "+
      "occasionally finds its way here.");
   add_item("tracks", (: TO, "do_tracks":));
   set_exits(([
      "north" : VILROOMS"k_road07",
      "east" : VILROOMS"house1",
	"south" : VILROOMS"k_road09"
   ]));
}

int do_tracks(){
   if(TP->query_nwp("tracking") <8){
      tell_object(TP,"You study the tracks but can't make out what they might mean.");
      tell_room(ETP,""+TPQCN+" leans down, studying something near the doorway.",TP);
      return 1;
   }
   tell_object(TP,"Leaning closer, you can tell that these tracks belong to orcs.  "+
      "Best be on your guard for the tricky little beasts.");
      tell_room(ETP,""+TPQCN+" leans down, studying something near the doorway.",TP);
      return 1;
}
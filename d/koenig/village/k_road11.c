//k_road11.c - Road through Koenig - coded by Circe 11/15/03
#include <std.h>
#include "../koenig.h"
inherit VILROADS;

void create() {
   ::create();
   set_long(
      "This narrow broken roadway leads through a ransacked village "+
      "that has clearly been abandoned.  Just to the northeast, a house stands, "+
      "though it can hardly be called such anymore.  There is no door on the "+
      "hinges, and the wood has been charred and blackened.  The windows stand "+
      "empty, allowing the wind to blow soot and ash out into the roadway.  "+
      "Strange smells still emanate from the decrepit building just to the "+
      "east of the path.  Intricate runes have been carved on what remains "+
      "of the doorway.  Just southwest of here, the pathway leads to a sloping "+
      "bank right into a rushing river."+
      "\n");
   add_item("windows","The empty window frames are charred and blackened by "+
      "flames that seem to have climbed up the side of the building.  Strange "+
      "clawmarks also mar the wooden surface.");
   add_item("house","The house has long been abandoned.  From the looks of it, "+
      "nothing now lives there, but the strange tracks outside the door suggest "+
      "that someone...or something...at least visits.");
   add_item("door","The door to the eastern building seems to be barely hanging on.  "+
      "Intricate runes were once carved on its surface and filled with molten silver, "+
      "Suggesting this was once one of the wealthier buildings in the village.  Now, "+
      "however, it stands blackened and charred like all the others.");
   add_item("runes","The once-delicate runes have been marred and muddled by the flames "+
      "that consumed this building.  In the center of the door, however, is a symbol known "+
      "by many to mean 'Apothecary.'");
   add_item("bank","The narrow bank to the southwest leads into a rushing river.  "+
      "It looks as though there would be room enough to have a picnic or wash clothes "+
      "there, but clearly there is no one left in the village to enjoy it.");
   add_item("river","The clear blue water of the river rushes over a smooth, sandy bottom.");
   add_item("tracks", (: TO, "do_tracks":));
   set_exits(([
      "north" : VILROOMS"k_road10",
      "northeast" : VILROOMS"house2",
      "east" : VILROOMS"apothecary",
      "southwest" : VILSTREAM"stream01"
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

//k_road11.c - Road through Koenig - coded by Circe 11/15/03
#include <std.h>
#include "../koenig.h"
inherit VILROADS;

void create() {
   ::create();
   set_long(
      "%^ORANGE%^This %^BOLD%^%^BLACK%^na%^RESET%^rr%^BOLD%^o%^BLACK%^w b%^RESET%^r%^BOLD%^o%^RESET%^ke%^BOLD%^%^BLACK%^n r%^WHITE%^oa%^RESET%^dw%^BOLD%^%^BLACK%^ay %^RESET%^%^ORANGE%^leads through a %^CYAN%^ransacked village %^ORANGE%^that has clearly been %^CYAN%^abandoned%^ORANGE%^. Just to the northeast, a %^BOLD%^%^RED%^house %^RESET%^%^ORANGE%^stands, though it can hardly be called such anymore. There is no door on the hinges, and the wood has been %^BOLD%^%^BLACK%^charred and blackened%^RESET%^%^ORANGE%^. The windows stand %^CYAN%^empty%^ORANGE%^, allowing the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^ind %^ORANGE%^to blow %^BOLD%^%^BLACK%^soot and ash %^RESET%^%^ORANGE%^out into the roadway. Strange %^BOLD%^%^BLACK%^s%^ORANGE%^m%^BLACK%^e%^ORANGE%^l%^BLACK%^ls %^RESET%^%^ORANGE%^still emanate from the %^CYAN%^decrepit %^BOLD%^%^RED%^building %^RESET%^%^ORANGE%^just to the east of the path.  Intricate %^CYAN%^r%^BOLD%^u%^ORANGE%^n%^CYAN%^e%^RESET%^%^CYAN%^s %^ORANGE%^have been carved on what remains of the doorway. Just southwest of here, the pathway leads to a %^BOLD%^%^CYAN%^sloping bank %^RESET%^%^ORANGE%^right into a %^BOLD%^%^CYAN%^rushing river%^RESET%^%^ORANGE%^.%^RESET%^"+
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

//k_road08.c - Road through Koenig - coded by Circe 11/15/03
#include <std.h>
#include "../koenig.h"
inherit VILROADS;

void create() {
   ::create();
   set_long(
      "%^RESET%^%^ORANGE%^This %^BOLD%^%^BLACK%^na%^RESET%^rr%^BOLD%^o%^BLACK%^w b%^RESET%^r%^BOLD%^o%^RESET%^ke%^BOLD%^%^BLACK%^n r%^WHITE%^oa%^RESET%^dw%^BOLD%^%^BLACK%^ay %^RESET%^%^ORANGE%^leads through a %^CYAN%^ransacked village %^ORANGE%^that has clearly been %^CYAN%^abandoned%^ORANGE%^. Just to the east, a %^BOLD%^%^RED%^house %^RESET%^%^ORANGE%^stands, though it can hardly be called such anymore. There is no door on the hinges, and the wood has been %^BOLD%^%^BLACK%^charred and blackened%^RESET%^%^ORANGE%^. The windows stand %^CYAN%^empty%^ORANGE%^, allowing the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^ind %^ORANGE%^to blow %^BOLD%^%^BLACK%^soot and ash %^RESET%^%^ORANGE%^out into the roadway. Through the northern window, a wooden %^BOLD%^crib %^RESET%^%^ORANGE%^can be seen. The road continues south into the village, or north into the %^BOLD%^%^GREEN%^forest %^RESET%^%^ORANGE%^pressing close around the buildings.%^RESET%^"+
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
//k_road10.c - Road through Koenig - coded by Circe 11/15/03
#include <std.h>
#include "../koenig.h"
inherit VILROADS;

void create() {
   ::create();
   set_long(
      "%^ORANGE%^This %^BOLD%^%^BLACK%^na%^RESET%^rr%^BOLD%^o%^BLACK%^w b%^RESET%^r%^BOLD%^o%^RESET%^ke%^BOLD%^%^BLACK%^n r%^WHITE%^oa%^RESET%^dw%^BOLD%^%^BLACK%^ay %^RESET%^%^ORANGE%^leads through a %^CYAN%^ransacked village %^ORANGE%^that has clearly been %^CYAN%^abandoned%^ORANGE%^. To the west is the front of an abandoned shop, its %^BOLD%^%^BLACK%^charred %^RESET%^%^ORANGE%^sign still reading '%^BOLD%^General Store%^RESET%^%^ORANGE%^.' Chains hang down in front of the windows and %^WHITE%^sm%^ORANGE%^a%^WHITE%^sh%^ORANGE%^e%^WHITE%^d %^ORANGE%^p%^WHITE%^o%^ORANGE%^t%^WHITE%^t%^ORANGE%^e%^WHITE%^ry %^ORANGE%^below reveals that the chains once held hanging baskets of flowers. Now, little remains of the store though the roof overhead seems somewhat sturdy. To the east, in the distance, another village home stands.%^RESET%^"+
      "\n");
   add_item("windows","The empty window frames are charred and blackened by "+
      "flames that seem to have climbed up the side of the building.  Strange "+
      "clawmarks also mar the wooden surface.");
   add_item("store","The store is eerily empty, with the hanging chains "+
      "clanging against the side of the building in the breeze.  The sign "+
      "is charred and faded, a grim reminder of the tragedy seen here.  "+
      "Strange tracks line the path in front of the door.");
   add_item("house","The house off the road to the east seems to sway slightly in "+
      "breeze.  Little is left of it.");
   add_items("chains","Thin metal chains bang against the side of the store.  They "+
      "hang empty now, but once held beautiful flowers in pots when the town "+
      "was still a peaceful place.");
   add_item("pottery","The broken pottery has been smashed beneath many feet.  "+
      "The dirt around them is now covered with strange tracks.");
   add_item("tracks", (: TO, "do_tracks":));
   set_exits(([
      "north" : VILROOMS"k_road09",
      "west" : VILROOMS"genstore",
	"south" : VILROOMS"k_road11"
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

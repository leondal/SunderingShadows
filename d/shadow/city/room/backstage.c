//Titania (6/29/19)
//Backstage Three Coins Theater, Shadow
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;
int searched;
#define RANDTREAS "/d/common/daemon/randtreasure_d"

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Backstage of the Three Coins Theater, Shadow");
   set_short("%^BOLD%^%^WHITE%^Backstage of the Three "+
   "Coins Theater, Shadow%^RESET%^");
   set_long("%^RESET%^This is a %^ORANGE%^plain room %^WHITE%^that "+ 
   "is likely always in its current state of disarray. Pieces "+ 
   "of %^MAGENTA%^costumes%^WHITE%^, %^CYAN%^backdrops%^WHITE%^, "+ 
   "%^BOLD%^%^BLACK%^discarded makeup%^RESET%^, "+ 
   "and %^BOLD%^scripts %^RESET%^thrust aside hastily "+ 
   "%^BOLD%^clutter %^RESET%^the space. You wonder how many "+ 
   "performers have sat here %^BOLD%^%^BLACK%^nervously%^RESET%^, "+ 
   "awaiting their cue to take the stage. Some of these performers "+ 
   "are captured in the many "+ 
   "%^BOLD%^%^MAGENTA%^p%^RESET%^%^RED%^a%^BOLD%^%^MAGENTA%^intin%^RESET%^%^MAGENTA%^g%^BOLD%^s "+ 
   "%^RESET%^that spread across the walls. "+ 
   "A set of %^BOLD%^stairs %^RESET%^lead farther into the theater.\n");
   set_smell("default","%^RESET%^%^CYAN%^It smells faintly of a "+ 
   "musky perfume.%^WHITE%^");
   set_listen("default","%^RESET%^%^BOLD%^Soft music drifts "+ 
   "up from down the stairs.%^RESET%^");
   set_items(([
      ({"costumes","backdrops","makeup","scripts","clutter"}) : "%^RESET%^%^CYAN%^Pieces "+
	  "of costumes, backdrops, discarded makeup, and "+
	  "scripts thrust aside clutter the space. Masks, shoes, "+ 
	  "fake weapons, and even the random instrument can all be found here.%^WHITE%^",
      ({"paintings","wall"}) : "%^RESET%^%^CYAN%^Many famous performers have passed "+
	  "through these halls, and this wall of fame attempts to show as many "+
	  "faces as possible. Some of the portraits are even autographed!%^WHITE%^",
      ({"stairs"}) : "%^RESET%^%^CYAN%^Soft music drifts up from down the stairs.%^WHITE%^",
   ]));
   set_search("default","%^BOLD%^%^WHITE%^It is possible there is "+ 
   "something of value in all that clutter.%^RESET%^");
   set_search("clutter", (: TO, "search_clutter" :) );
   set_search("costumes", (: TO, "search_clutter" :) );
   set_exits(([
      "out" : ROOMS"theater",
	  "down" : ROOMS"bardguild",
   ]));
}

void search_clutter(string str) {
   if(searched) {
     write("%^BOLD%^%^BLUE%^Somebody already got all the good stuff.%^RESET%^");
     return;
   }
   if(!random(3)) {
      write("%^BOLD%^%^GREEN%^There's nothing much of interest here.%^RESET%^");
      tell_room(ETP,""+TPQCN+" doesn't seem to find anything interesting.", TP);
      searched = 1;
      return;
   }
   RANDTREAS->find_stuff(TO,"random");
   write("%^YELLOW%^You find something!%^RESET%^\n");
   tell_room(ETP,""+TPQCN+" finds something!", TP);
   searched = 1;
   return;
}


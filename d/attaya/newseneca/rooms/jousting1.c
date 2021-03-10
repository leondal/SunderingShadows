//jousting1.c - Jousting grounds for new Seneca
//Purely an RP area right now ~Circe~ 11/28/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_light(3);
   set_indoors(0);
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   set_name("The Lists, Seneca");
   set_short("%^BOLD%^The Lists, Seneca%^RESET%^");
   set_long("%^BOLD%^The Lists, Seneca%^RESET%^\n"+
      "Surrounded by a %^BOLD%^white picket fence%^RESET%^, this open "+
      "area is covered by lush %^BOLD%^%^GREEN%^grass %^RESET%^that "+
      "dances on the %^CYAN%^breeze%^RESET%^ rising continually "+
      "from the %^BOLD%^%^CYAN%^sea%^RESET%^.  A long, wide %^ORANGE%^"+
      "strip %^RESET%^in the center looks to have been repeatedly "+
      "trampled and stripped of grass from the many %^BOLD%^jousting "+
      "tournaments %^RESET%^held here.  To the east and west, lining "+
      "the fence, several long %^ORANGE%^wooden benches %^RESET%^"+
      "have been constructed with the shortest in front.  They rise "+
      "in height until the third bench, which forms the back row, is "+
      "the tallest.  Just in front of the first row is a low %^ORANGE%^"+
      "railing %^RESET%^to keep spectators from interfering with the "+
      "events.  Several of the benches still sport %^CYAN%^c%^GREEN%^"+
      "o%^BLUE%^l%^RED%^o%^ORANGE%^r%^YELLOW%^f%^RESET%^u%^MAGENTA%^l "+
      "%^RESET%^%^BOLD%^pennants %^RESET%^of favorite knights from "+
      "prior contests.  This portion of the %^BOLD%^lists %^RESET%^is where "+
      "the %^RED%^tournament of lances %^RESET%^takes place, and it "+
      "provides ample room for the knights and their horses.\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      "grass" : "%^BOLD%^%^GREEN%^The grass here is just a shade shy of "+
         "being called long.  Unlike the grass found in the rest of "+
         "Seneca, this must have been tended because it is soft and "+
         "smooth.  Perhaps it's all the horse manure?%^RESET%^",
      "strip" : "%^ORANGE%^The central area is a wide, grass-free "+
         "strip that runs all the way from the gate to the end of the "+
         "benches.  It is here that mounted combat takes place, and "+
         "the grass is continually removed when the horses charge "+
         "at each other.%^RESET%^",
      ({"fence","picket fence","white picket fence"}) : "%^BOLD%^The "+
         "white picket fence surrounding the Lists is relatively "+
         "short.  It has a gate set within it to the south that leads "+
         "back to %^RESET%^%^GREEN%^Verde Esplanade%^BOLD%^%^WHITE%^, "+
         "while northward it continues well past the benches.%^RESET%^",
      ({"bench","benches","wooden bench","wooden benches"}) : "%^ORANGE%^"+
         "The wooden benches are rather narrow but long, supported by "+
         "many wooden posts.  The first is only about two feet in height, "+
         "while the second is about a foot taller, and the last row "+
         "another foot still.  The arrangement gives plenty of room "+
         "for spectators to enjoy the show.%^RESET%^",
      "railing" : "The railing in front of the first row of benches "+
         "is about four feet tall and made of a single slender "+
         "log planed smooth and placed on supports.  It provides a "+
         "visual cue to let spectators know to stay out of the field.",
      ({"pennant","pennants","colorful pennants"}) : "None of the "+
         "pennants are whole - rather, there are bits and pieces of "+
         "old symbols of support left where they have been caught "+
         "on the wood of the benches.  Each knight has a particular "+
         "set of colors, and spectators often bring small flags "+
         "bearing those colors to show their allegiance."
   ]));
   set_exits(([
      "south" : ROOMS"sstreet25",
      "north" : ROOMS"jousting2"
   ]));
   set_door("gate","/d/attaya/newseneca/rooms/sstreet25","south",0,0);
   set_door_description("gate","The gate through the %^BOLD%^white "+
      "picket fence %^RESET%^is wide, easily allowing a horse or two "+
      "to pass through.  It has a %^BOLD%^%^BLACK%^wrought iron latch%^RESET%^.");
}

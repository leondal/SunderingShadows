//jousting2.c - Jousting grounds for new Seneca
//Purely an RP area right now ~Circe~ 11/28/07
#include <std.h>
#include "../seneca.h"

inherit ROOM;

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
      "from the %^BOLD%^%^CYAN%^sea%^RESET%^.  Two large %^ORANGE%^"+
      "circles %^RESET%^devoid of grass dominate the northeastern "+
      "and southwestern corners respectively.  These circles are "+
      "home to the %^YELLOW%^contests%^RESET%^ of weapons that "+
      "take place during %^BOLD%^tournaments%^RESET%^.  Surrounding "+
      "each arena is a circle of %^ORANGE%^wooden benches %^RESET%^"+
      "placed a safe distance away.  This part of the lists can "+
      "sometimes be chaotic with two events happening concurrently, "+
      "but the %^GREEN%^jousting field %^RESET%^to the south "+
      "invariably draws larger crowds.\n");
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
      ({"circle","circles"}) : "%^ORANGE%^Each circle is large, giving "+
         "the knights plenty of room to maneuver with the chosen "+
         "weapon.  Knights are expected to be proficient with many "+
         "weapons, so you may at times see them competing here with "+
         "swords, axes, or hammers.%^RESET%^",
      ({"fence","picket fence","white picket fence"}) : "%^BOLD%^The "+
         "white picket fence surrounding the Lists is relatively "+
         "short.  The fence encloses the area to the north, while "+
         "it opens to the south for the jousting grounds.%^RESET%^",
      ({"bench","benches","wooden bench","wooden benches"}) : "%^ORANGE%^"+
         "The wooden benches here are short and arranged in a "+
         "choppy circle around each competition circle to allow "+
         "spectators a good view of the events.%^RESET%^",
   ]));
   set_exits(([
      "south" : ROOMS"jousting1"
   ]));
}

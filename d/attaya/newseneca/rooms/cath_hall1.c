//cath_hall1.c 
//for new Seneca ~Circe~ 3/10/08
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Hallway of the Cathedral, Seneca");
   set_short("Hallway of the Cathedral, Seneca");
   set_long("%^BOLD%^Hallway of the Cathedral, Seneca%^RESET%^\n"+
      "The close stone walls bordering this hallway have been "+
      "%^BOLD%^whitewashed%^RESET%^, creating a clean atmosphere.  "+
      "Wide %^ORANGE%^arches %^RESET%^supported with varnished "+
      "%^ORANGE%^oak%^RESET%^ open onto large common rooms to the "+
      "east and west.  The western arch leads into a true common "+
      "room, complete with simple %^ORANGE%^benches %^RESET%^"+
      "gathered around a stone %^RED%^fireplace%^RESET%^.  The "+
      "eastern room is a %^BOLD%^workroom %^RESET%^where monks "+
      "may practice their chosen craft.  To the south, the hallway "+
      "leads to the stairway while it winds to the monks' cells "+
      "northward.  The floor here is smooth, "+
      "undressed %^BOLD%^stone%^RESET%^ that is clearly more "+
      "functional than decorative, perfect for the monks' stoic "+
      "lifestyle.\n");
   set_exits(([
      "west" : ROOMS"cath_living",
      "east" : ROOMS"cath_workroom",
      "south" : ROOMS"cath_basement",
      "north" : ROOMS"cath_hall2"
   ]));
   set_smell("default","The light fragrance of beeswax fills the air.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"wall","walls"}) : "%^BOLD%^%^WHITE%^The stone walls are "+
         "smooth and whitewashed for a pristine appearance.%^RESET%^",
      "floor" : "The smooth stone floor was hewn at one point but "+
         "has also been worn by countless feet over the years, "+
         "making it seem almost soft.",
      ({"hall","hallway"}) : "The hallway here continues to the "+
         "south and north, leading to countless other doors in "+
         "that direction.",
      ({"common room","fireplace","benches"}) : "The room to the "+
         "west features simple %^ORANGE%^wooden benches %^RESET%^"+
         "in good repair gathered around a large %^RED%^fireplace "+
         "%^RESET%^in the western wall.  It seems the monks gather "+
         "here to enjoy the fellowship of their brothers.",
      "workroom" : "The workroom to the east is filled with work "+
         "benches, tools, and all manner of supplies needed to "+
         "practice a variety of crafts.  The monks here each "+
         "take up a vocation to both better perfect themselves and "+
         "to help support the monastery.  Some cook, others clean, "+
         "but still many others work here, providing the monastery "+
         "with needed materials.",
      "stairway" : "The southern hallway leads to the %^BOLD%^"+
         "marble stairway%^RESET%^ to reach the upper floor."
   ]));
}

//cath_basement.c 
//for new Seneca ~Circe~ 4/2/08
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
      "The thick %^BOLD%^marble stairway %^RESET%^opens up into "+
      "this narrow hallway.  The close stone walls here have been "+
      "%^BOLD%^whitewashed%^RESET%^, creating a clean atmosphere.  "+
      "Wide %^ORANGE%^arches %^RESET%^supported with varnished "+
      "%^ORANGE%^oak%^RESET%^ open onto large common rooms to the "+
      "east and west.  The western arch leads into a %^YELLOW%^"+
      "quiet study%^RESET%^ where monks can be found at all times, "+
      "absorbed in their own pursuits of knowledge.  The "+
      "eastern room is a %^BOLD%^kitchen %^RESET%^where monks "+
      "volunteer to prepare food for their brethren.  A few "+
      "round %^ORANGE%^tables%^RESET%^ with simple %^ORANGE%^"+
      "stools%^RESET%^ are also spread around the room, giving "+
      "the monks places to eat.  To the south, the hallway "+
      "leads to the stairway while it winds to the monks' cells "+
      "northward.  The floor here is smooth, "+
      "undressed %^BOLD%^stone%^RESET%^ that is clearly more "+
      "functional than decorative, perfect for the monks' stoic "+
      "lifestyle.\n");
   set_exits(([
      "west" : ROOMS"cath_study",
      "east" : ROOMS"cath_kitchen",
      "up" : ROOMS"cath_vestry",
      "north" : ROOMS"cath_hall1"
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
         "north, leading to countless other doors in "+
         "that direction.  To the south, a marble stairway rises "+
         "into the upper reaches of the cathedral.",
      ({"study","quiet study"}) : "The cozy room to the west is "+
         "filled with various chairs and desks arranged for "+
         "study.  Tall %^BOLD%^beeswax candles%^RESET%^ are "+
         "scattered throughout, offering plenty of illumination.",
      "kitchen" : "The eastern kitchen feels crowded with all "+
         "the round %^ORANGE%^tables%^RESET%^ and %^ORANGE%^"+
         "stools%^RESET%^ provided for the monks.  The far eastern "+
         "wall holds several grated %^BOLD%^%^RED%^fi%^YELLOW%^r"+
         "%^RED%^es%^RESET%^ and %^BOLD%^%^BLACK%^stoves%^RESET%^ "+
         "while %^BOLD%^%^BLACK%^pots%^RESET%^, %^BOLD%^%^BLACK%^"+
         "pans%^RESET%^, and other %^BOLD%^utensils%^RESET%^ hang "+
         "from %^ORANGE%^wooden racks %^RESET%^suspended from the "+
         "ceiling.",
      ({"stairs","stairway","staircase"}) : 
         "The narrow stairway is carved from beautiful "+
         "%^BOLD%^white marble%^RESET%^ and has worn smooth over "+
         "the centuries.  It provides access to the upper reaches "+
         "of the cathedral proper."
   ]));
}

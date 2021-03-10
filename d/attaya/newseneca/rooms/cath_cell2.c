//cath_cell2.c - monk's cell of the cathedral
//for new Seneca ~Circe~ 2/05/08
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Monk's Cell of the Cathedral, Seneca");
   set_short("Monk's Cell of the Cathedral, Seneca");
   set_long("%^BOLD%^Monk's Cell of the Cathedral, Seneca%^RESET%^\n"+
      "This small room is roughly square in shape, featuring "+
      "%^BOLD%^whitewashed walls %^RESET%^fitted with %^ORANGE%^"+
      "brass sconces %^RESET%^holding thick %^BOLD%^beeswax "+
      "candles%^RESET%^.  The candles provide the only "+
      "%^YELLOW%^illumination%^RESET%^ here beneath the cathedral, "+
      "casting their meager, flickering light upon the sparse "+
      "furnishings of the chamber.  Along the far wall, a hard, "+
      "narrow %^ORANGE%^bed %^RESET%^with a single thin blanket "+
      "stands beside the room's only %^ORANGE%^table%^RESET%^.  "+
      "The northern wall houses a small %^BOLD%^shrine%^RESET%^ "+
      "often decorated to appeal to a mixture of the deities, "+
      "depending upon this monk's personal preference.  Balancing "+
      "this display along the southern wall is a thick %^ORANGE%^"+
      "wooden chest%^RESET%^ most likely used to house spare "+
      "%^ORANGE%^r%^YELLOW%^o%^RESET%^%^ORANGE%^b%^YELLOW%^e"+
      "%^RESET%^%^ORANGE%^s %^RESET%^and other such materials.  "+
      "The temperature here is comfortably cool year-round, "+
      "compliments of its location underground.\n");
   set_exits(([
      "west" : ROOMS"cath_hall2"
   ]));
   set_smell("default","The light fragrance of beeswax fills the air.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"stairs","stairway","white stairway","white marble stairway","marble stairway"}) :
         "Leading down into the darkened basement, the white "+
         "marble stairway is rather narrow and looks to have "+
         "been carved for both function and beauty, much like the "+
         "rest of the cathedral.  In the recesses of the basement, "+
         "many of the monks live and study, spending out their "+
         "entire lives in the warrens below.",
      ({"sconce","sconces","brass sconces","candles"}) : 
         "The only illumination of the room is "+
         "provided by the few candles that burn in simple "+
         "brass sconces fitted with glass lids.  The room "+
         "features four in total, one on each wall.",
      ({"bed","blanket"}) : "The far wall is lined with a small, "+
         "narrow bed with a simple wooden frame and a thin "+
         "mattress.  It is covered by a simple blanket, and there "+
         "is no pillow to be found.",
      "table" : "A simple affair of four legs and a square top, "+
         "this table is placed by the bed.  It looks to be used "+
         "as a nightstand, or it may be pulled around and used "+
         "as a writing desk for someone sitting on the bed.",
      ({"wall","walls","whitewashed walls"}) : "The stone walls "+
         "of the cell have been whitewashed, giving them a "+
         "clean appearance.",
      "shrine" : "The shrine looks to be a recessed area in the "+
         "wall.  The shelf formed is filled with tokens of several "+
         "different gods, and it looks as though the occupant "+
         "gives prayers and offerings often.",
      ({"chest","wooden chest"}) : "The wooden chest is bound "+
         "in brass and features a clasp but no lock.  It is used "+
         "to store robes, other clothing, and what minor effects "+
         "the monk who lives here may have."
   ]));
   set_door("weathered door","/d/attaya/newseneca/rooms/cath_hall2","west",0);
   set_door_description("weathered door","%^ORANGE%^The simple oaken door "+
      "set in the western wall looks as though it has seen better "+
      "times.  It has a thick %^BOLD%^%^BLACK%^iron pull ring "+
      "%^RESET%^%^ORANGE%^that may "+
      "be used to close it.%^RESET%^");
}

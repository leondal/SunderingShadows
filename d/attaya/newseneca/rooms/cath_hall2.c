//cath_hall2.c - monk's cell of the cathedral
//for new Seneca ~Circe~ 2/12/08
#include <std.h>
#include "../seneca.h"

inherit VAULT;

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
      "Simple %^ORANGE%^oaken doors %^RESET%^with arched tops "+
      "are spaced evenly along the eastern and western walls, "+
      "leading to the monks' small cells.  The hallway continues "+
      "in much the same way, spiralling downward to the north with "+
      "doors marching along its length.  The floor here is smooth, "+
      "undressed %^BOLD%^stone%^RESET%^ that is clearly more "+
      "functional than decorative, perfect for the monks' stoic "+
      "lifestyle.\n");
   set_exits(([
      "west" : ROOMS"cath_cell1",
      "east" : ROOMS"cath_cell2",
      "south" : ROOMS"cath_hall1"
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
      ({"doors","oak doors","oaken doors"}) : "%^ORANGE%^The doors "+
         "lining the hallway on either side are oaken and feature "+
         "arched tops.  They are opened by means of simple %^BOLD%^"+
         "%^BLACK%^iron pullrings%^RESET%^%^ORANGE%^.%^RESET%^",
      "floor" : "The smooth stone floor was hewn at one point but "+
         "has also been worn by countless feet over the years, "+
         "making it seem almost soft.",
      ({"hall","hallway"}) : "The hallway here continues to the "+
         "south and north, leading to countless other doors in "+
         "that direction.  All doors seem to be the same as the "+
         "ones leading to the monks' cells here."
   ]));
   set_door("weathered door","/d/attaya/newseneca/rooms/cath_cell2","east",0);
   set_door_description("weathered door","%^ORANGE%^The simple oaken door "+
      "set in the eastern wall looks as though it has seen better "+
      "times.  It has a thick %^BOLD%^%^BLACK%^iron pull ring "+
      "%^RESET%^%^ORANGE%^that may be used to close it.%^RESET%^");
   set_door("door","/d/attaya/newseneca/rooms/cath_cell1","west",0);
   set_door_description("door","%^ORANGE%^The simple oaken door "+
      "set in the western wall is lightly varnished and has a "+
      "simple %^BOLD%^%^BLACK%^iron pull ring %^RESET%^%^ORANGE%^that may "+
      "be used to close it.%^RESET%^");
}

//general_store.c by ~Circe~ for new Seneca 11/20/07
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(WOOD_BUILDING);
   set_light(2);
   set_indoors(1);
   set_name("General Store, Seneca");
   set_short("General Store, Seneca");
   set_long("%^BOLD%^General Store, Seneca%^RESET%^\n"+
      "The walls of this shop are %^BOLD%^cream-colored stucco%^RESET%^ "+
      "and support %^ORANGE%^shelves %^RESET%^stocked with all manner "+
      "of %^GREEN%^items %^RESET%^and %^BOLD%^%^BLACK%^equipment %^RESET%^"+
      "needed for both everyday life and adventuring.  Sacks and pouches "+
      "are folded neatly, arranged by size, beside lanterns, coils of rope, "+
      "and various other odds and ends.  One particular shelf holds leisure "+
      "items such as dice and cards, while another is filled with paper, "+
      "parchment, ink, and quills.  A sturdy %^ORANGE%^wooden counter "+
      "%^RESET%^and matching chair dominate most of the floor of the "+
      "room, providing the shopkeeper with a comfortable place to "+
      "conduct business.  A stairway in the very back of the room leads "+
      "up, likely to the shopkeeper's living quarters.\n\n"+
      "%^BOLD%^<%^RESET%^help shop%^BOLD%^> %^RESET%^will "+
      "show you a list of commands to use here.\n");
   set_items(([
      ({"shelves","shelf"}) : "The shelves are wide enough to hold "+
         "many different types of supplies.  They line the walls and "+
         "are stocked both neatly and logically.",
      ({"items","equipment"}) : "You see not only adventuring "+
         "equipment but also common items such as salt and flour "+
         "that the people of Seneca might need.",
      ({"counter","chair","wooden counter"}) : "The thick wooden "+
         "counter is about three feet wide, giving the shopkeeper "+
         "plenty of space.  It has a few nicks and dings, likely "+
         "from the exchange of goods across its surface.  The chair "+
         "has a tall back and arms, as well as a thick cushion for "+
         "comfort.",
      ({"stairs","stairway"}) : "The narrow stairway in the back "+
         "leads to a private area and does not seem open to the public."
   ]));
   set_exits(([
      "west" : ROOMS"skyline45"
   ]));
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
}

void reset(){
   ::reset();
   if(!present("gstorekeeper",TO))
      new(MON"seneca_clerk")->move(TO);
}

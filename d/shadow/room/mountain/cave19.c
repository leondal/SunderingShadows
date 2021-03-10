//cave19.c
#include <std.h>
#include "echoes.h"

inherit CROOM;

void create(){
    set_monsters( ({MOBS"worker", MOBS"dwarf"}), ({2,1}) );
    ::create();
    set_repop(50);
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",1);
    set_name("Inside Echoes Mountains");
    set_short("Inside Echoes Mountains");
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The smooth, %^BOLD%^%^BLACK%^dark gray walls %^RESET%^of this tunnel through Echoes Mountains seem "+
      "partially naturally carved.  Some signs of fantastic workmanship suggest "+
      "that the dwarves who make their home here have expanded and improved upon "+
      "nature's beauty.  The %^BOLD%^%^BLUE%^vaulted ceilings %^RESET%^are supported and decorated by "+
      "%^YELLOW%^archways %^RESET%^carved of stone and placed every fifteen feet without variance.  "+
      "%^BOLD%^%^BLUE%^Columns %^RESET%^carved in relief march along the walls between the arches, "+
      "creating a sense of being in the open air despite the drab walls of the tunnels.  A slight "+
      "draft comes from the northern tunnel, where the ground begins sloping upward significantly."
      "\n"
    );
     set_items(([
      (({"wall","walls","gray walls","stone walls"})) : "The dark gray stone walls "+
         "are perfectly smooth except for the carved columns and archways.  Aging "+
         "spots and darker gray stone in places suggest that these tunnels have "+
         "stood for some time and that they were probably initially naturally "+
         "carved.",
      (({"ceiling","ceilings","vaulted ceilings"})) : "The ceiling of the tunnel "+
         "rises high overhead, making the caverns seem open rather than stuffy.  "+
         "From what you can see, they seem to be hewn smooth between the archways.",
      (({"archway","archways"})) : "The tall archways are set into the walls and "+
         "curve as they near the ceiling, being lost in the shadows above.  They "+
         "have the simple, elegant lines characteristic of dwarven stonework.",
      (({"column","columns"})) : "The rounded columns protruding from the walls "+
         "of the tunnel are fluted but otherwise very simple.  They are well-made "+
         "and show very few signs of wear, indicating that they are maintained.",
      (({"floor","ground"})) : "The stone floor of the tunnels is strewn with a "+
         "light covering of dust and occasional small rocks.  For the most part, "+
         "it is quite clean and smooth, but rises and falls, making travel a "+
         "little difficult." 
	]));
   set_smell("default","You smell the slightly stale air of the tunnels.");
   set_listen("default","You hear the reverberance of echoes throughout the caves.");

    set_exits(([
        "east" : ROOMS"cave18",
        "north" : "/d/shadow/room/kildare/rooms/cave1"
        ]));
}

void reset() {
  ::reset();
/* changing to use CROOM for control of wandering mobs over longer reboots
*Styx* 11/29/02
  if(!present("mountain dwarf")) {
    new("/d/shadow/room/mountain/mons/worker")->move(TO);
    new("/d/shadow/room/mountain/mons/worker")->move(TO);
  }
  if(!present("guard")) {
   if(sizeof(children("/d/shadow/room/mountain/mons/dwarf")) < 10) 
    new("/d/shadow/room/mountain/mons/dwarf")->move(TO);
  }
*/
}

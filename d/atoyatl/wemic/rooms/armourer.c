#include <std.h>
#include "../wemic.h"
inherit ROOM;

void create(){
	::create();
	set_property("indoors",1);
	set_short("Wemic Armory");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    	set_long(
   "%^ORANGE%^In the centre of the room a huge vat sits above a large open"
  +" fire.  It is vented through a hole in the roof, but the stench in the"
  +" room suggests that this concession to breathability is not enough. "
  +" Racks of drying hides are lined up against the north wall.  In the"
  +" southern area, a sturdy workbench is set up, well equipped with"
  +" blades, hammers, tongs, punches and other implements useful in the"
  +" working of bone and leather.  A series of bone frames in the space to"
  +" the west of the vat display an array of finished pieces of armor."
    	);
	set_property("light",2);
    	set_smell("default", "A throat-clogging stench of burned and treated"
                          +" leather threatens to overwhelm your senses.");
    	set_listen("default", "The shop is relatively quiet.");
	set_items(([
		({"walls","shelves","equipment","weapons"}) : "The various items that the "+
			"store sells are hung on the walls and stocked on the shelves "+
			"about the store. If you're wanting to look at something, the "+
			"shop keeper will be more than happy to show it to you.",
	]));
	set_exits(([
		"southwest" : ROOMS + "path06",
                "north" : ROOMS + "path16",
                 "east" : ROOMS + "path17"
	]));
}

void reset() {
   	::reset();
   	if(!present("pietrrr")) {
      	new(MOB+"pietrrr")->move(TO);
   	}
}

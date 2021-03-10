#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("Guard Barracks");
	set_long(
	"This is a standard guard barracks. The floor is rather dirty"+
	" and could use a good mopping. The guards have tracked a lot"+
	" of dirt in here and it looks like some liquor's been spilled"+
	" on the floor as well. There are several rather small bunk beds,"+
	" all lined up against the back walls. There's a chest in front"+
	" of each bunk bed, each filled with extra clothing and things"+
	" like that. Eight soldiers could sleep in here at a time. Lamps"+
	" have been fixed at intervals along the walls of the room and"+
	" can be lit to provide light. There's a round wooden table in"+
	" the right corner near the door with several chairs around it,"+
	" probably for playing games."
	);
	set_smell("default","It smells like dirty laundry and spilt booze.");
	if(query_night() == 1) {
		set_listen("default","You hear the obnoxious snoring of the"+
		" guards.");
	}
	else {
		set_listen("default","The chatter of the guards fills the"+
		" room.");
	}
	set_items(([
	({"beds","bunk beds","bunk bed","bed"}) : "There are four sets of"+
	" bunk beds, all lined up against the back of the room.",
	({"trunk","chest"}) : "A chest rests in front of each bunk bed"+
	" and holds clothing.",
	({"laundry","clothing"}) : "There is a lot of clothing in the"+
	" chests, some of it still looks dirty.",
	"table" : "There is a round wooden table tucked into the right"+
	" corner near the door. It's probably used for playing games.",
	"chairs" : "Several wooden chairs are placed around the table.",
	"floor" : "The floor desperately needs to be cleaned. It is"+
	" covered in dirt and mud and there are several sticky spots"+
	" in places where drinks have been spilled.",
	]));
	set_exits(([
	"east" : ROOMS+"street1",
        "north" : ROOMS+"jail_main",
	]));
	set_door("door",ROOMS+"street1","east",0);
}

void reset()
{
   ::reset();
   if(!present("guard")) {
      switch(random(3)) {
         case 0:
            new(MONS+"guard")->move(TO);
            new(MONS+"guard")->move(TO);
            break;
         case 1:
            new(MONS+"guard")->move(TO);
            new(MONS+"guard")->move(TO);
            new(MONS+"guard")->move(TO);
            break;
         case 2:
            new(MONS+"guard")->move(TO);
            new(MONS+"guard")->move(TO);
            new(MONS+"guard")->move(TO);
            new(MONS+"guard")->move(TO);
            break;
      }
   }
}

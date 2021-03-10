#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
	set_property("indoors",1);
	set_property("light",2);
	set_short("A guard tower");
	set_long(
	"This is the second floor of a sturdy stone guard tower. A window"+
	" on the southern side over looks the Antioch gates. There are"+
	" several slits along the walls for archers to fire through. A"+
	" small round wooden table takes up one corner of the room away"+
	" from the windows and there are several tools near it that can"+
	" be used to sharpen weapons. A large lantern hangs from a chain"+
	" in the ceiling, shedding light on the room. A rack of bows"+
	" is set up across the room from the table and a barrel full of"+
	" arrows sits next to it. Large stone steps wind back down to"+
	" the first floor, curving out of sight."
	);
	set_smell("default","You can smell the sweat from the guards who"+
	" keep watch.");
	set_listen("default","You can hear the idle chatter from the"+
	" guards down stairs.");
	set_items(([
	({"steps","step","stone step","stone steps"}) : "Large stone"+
	" steps lead down to the first floor.",
	"table" : "A small wooden table is tucked away in one corner"+
	" with a few chairs around it.",
	"tools" : "There are several tools used to sharpen weapons on"+
	" the floor near the table.",
	({"rack","arrows","bows","barrel"}) : "A rack of bows is kept"+
	" in one corner of the room, a barrel full of arrows sits next"+
	" to it.",
	"window" : "The window is on the south side of the room, over"+
	" looking the Antioch gates.",
	({"ceiling","lamp"}) : "A large lamp hangs from a chain attached"+
	" to the ceiling, lighting up the entire room.",
	"floor" : "The floor is made of square stone blocks and looks"+
	" very sturdy.",
	"room" : "The room is made from sturdy stone blocks and is round"+
	" in shape, reaching up to form a domed ceiling.",
	]));
	set_exits(([
	"stairs" : ROOMS+"gtower",
	]));
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
   return;
}

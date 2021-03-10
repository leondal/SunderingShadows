#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("A little kitchen");
	set_long(
	"This is a small little kitchen that is closed off by some rather"+
	" thin walls from the rest of the house. There is a counter with"+
	" a sink and a cutting board on it. Cabinets are placed above the"+
	" counter as well as below. Drawers are built beneath the counter,"+
   " probably containing silver ware. Hanging by pegs from the"+
	" eastern wall are several pots and pans. There is a stove and"+
	" oven on the south wall. Several different herbs and spices are"+
	" sitting out in jars on a counter near the stove. There are two"+
	" windows, probably to let the heat and smoke out. One is above"+
	" the sink and one is on the east wall. They are fairly simple and"+
	" made of glass. Wood runs down the center of them and they can be"+
	" opened outwards. It is a rather simple kitchen, but it serves"+
	" its purpose. \n %^RESET%^%^CYAN%^A bunch of spears"
" are standing on end around the cabinet for some odd reason.  They do not move"
" and appear to be quite thick, five layers deep at least.  What is somebody so afraid of?"
	);
	set_smell("default","You can smell different herbs and spices.");
	set_listen("default","The house is quiet.");
	set_items(([
	"floor" : "The floor is made of wood and kept very clean.",
	"ceiling" : "A lamp hangs down from the center of the ceiling,"+
	" giving light to the room.",
	({"wall","walls"}) : "%^BOLD%^The walls are white and very thin.",
	"lamp" : "A large lamp hangs down from the center of the ceiling,"+
	" providing the room with light.",
	({"window","windows"}) : "There are two windows, one on the south"+
	" wall above the sink, and one on the eastern wall. Wood splits"+
	" them down the center and they can be opened outwards to let"+
	" the heat and smoke out of the room.",
	"counter" : "A large counter stretches around most of the room,"+
	" almost in a U shape, except for the stove on the north wall.",
	"cutting board" : "There is a cutting board on top of the counter"+
	" on the south wall that looks fairly new.",
	({"stove","oven"}) : "On the north side of the room is an oven"+
	" with a stove on top of it. It is fairly plain but has been kept"+
	" very clean.",
	({"herbs","spices","jars"}) : "Next to the stove are several jars"+
	" of dried herbs and spices. Their aroma fills the room.",
	({"pots","pans"}) : "Next to the window on the eastern wall pots"+
	" and pans are hung from pegs.",
	"pegs" : "Simple wooden pegs have been fixed to the east wall,"+
	" pots and pans hang from them.",
	"sink" : "There is a large metal sink on the southern wall. It"+
	" has a little spicket that you can pump water from.",
	"cabinets" : "On the south wall above the counter are several"+
	" cabinets that the dishes are kept in.",
	"drawers" : "Beneath the counter are several drawers that the"+
   " silver ware is probably kept in. ",
	]));
	set_exits(([
	"house" : ROOMS+"house2",
      "cave" : "/realms/tsera/tempdrow/drcave1.c",
	]));
      set_invis_exits( ({"cave"}) );
}

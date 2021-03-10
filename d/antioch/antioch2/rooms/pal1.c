#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("%^YELLOW%^Palace of Antioch");
	set_long(
	"This is the entrance of the grand palace of Antioch. A large rug covers"+
	" the floor, rolling away to the east and west and up to the north. The"+
	" rug is finely woven and is predominantly %^YELLOW%^gold%^RESET%^ with"+
	" %^RED%^crimson%^RESET%^ stripes on the edges. Hanging down from the"+
	" ceiling is a large silk banner with the crest of the Antioch palace on"+
	" it. The crest is a %^BOLD%^white pegasus%^RESET%^ on a royal %^MAGENTA%^purple%^RESET%^"+
	" background. The walls of the palace have been plastered to keep the"+
	" cold out and the heat in. They've been painted a %^BOLD%^%^RED%^light"+
	" red%^RESET%^ color. Elaborate tapestries cover most of the walls,"+
	" adding to the extravagent feeling here. Between the tapestries oil lamps"+
	" are fixed against the walls, giving light to the rooms."
	);
	set_smell("default","The faint scent of oranges is in the air."); 
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching away to the east"+
	" and west and off to the north. It is finely woven and quite thick and"+
	" sturdy. %^YELLOW%^Gold%^RESET%^ is the primary color of the rug, and"+
	" a few slender %^RED%^crimson%^RESET%^ stripes line the edges.",
	({"banner","silk banner","crest"}) : "A silk banner hangs down from the"+
	" ceiling with the royal crest of Antioch sewn onto it. A beautiful"+
	" %^BOLD%^white pegasus%^RESET%^ stands sideways on a field of royal"+
	" %^MAGENTA%^purple%^RESET%^. Legend tells that the royal family used"+
	" to befriend and ride pegasi that were said to live in the upper reaches"+
	" of the mountain. Although no pegasus has been seen for a hundred years,"+
	" the legend still stands and the noble beast remains the sign of Antioch's"+
	" royalty.",
	({"tapestry","tapestries"}) : "Extravagent tapestries line the walls of"+
	" the hallways.",
	({"wall","walls"}) : "The walls have been covered in plaster to help keep"+
	" the heat in and the cold out. They have been painted over in a %^BOLD%^%^RED%^light"+
	" red%^RESET%^ shade. Extravagent tapestries cover most of the walls"+
	" with oil lamps positioned inbetween them.",
	"floor" : "The floor is covered in a large rug.",
	"ceiling" : "From the ceiling hangs a large banner bearing the royal"+
	" crest of Antioch.",
	({"lamp","lamps","oil lamp","oil lamps"}) : "%^YELLOW%^Golden tinted oil"+
	" lamps are fixed to the walls at intervals between the tapestries. The"+
	" lamps shed light to the room, but as they burn they also give off the"+
	" pleasant smell of oranges.",
	"pegasus" : "%^BOLD%^A beautiful and magestic pegasus stands proudly on"+
	" the silk banner. He is standing sideways with his head arced proudly"+
	" and his magnificent wings spread upwards. He appears to be in mid-gallop,"+
	" as though he is just about to take off into flight.",
	]));
	set_exits(([
	"south" : ROOMS+"street25",
	"west" : ROOMS+"pal4",
	"east" : ROOMS+"pal2",
	"north" : ROOMS+"pal6",
	]));
}

void reset()
{
   ::reset();
   if(!present("royal guard 2")) {
      new(MONS+"royal_guard")->move(TO);
   }
   if(!present("royal guard 2")) {
      new(MONS+"royal_guard")->move(TO);
   }
   return;
}

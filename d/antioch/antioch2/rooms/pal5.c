#include <std.h>
#include "../antioch.h"
inherit VAULT;

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
	"This is a hallway in Antioch's palace that leads to a component shop."+
	" The floor is covered in a %^YELLOW%^gold%^RESET%^ and %^RED%^crimson%^RESET%^"+
	" rug that stretches to the north and east. To the north is a walnut door"+
	" with the mage's sign engraved into the center of it. On the western"+
	" wall is a beautiful tapestry of a %^ORANGE%^bronze dragon%^RESET%^"+
	" in flight. The tapestry is a lovely %^BOLD%^%^CYAN%^sky blue%^RESET%^"+
	" with a few fluffy %^BOLD%^white clouds%^RESET%^ drifting in the background."+
	" A few %^YELLOW%^gold tinted%^RESET%^ oil lamps are placed at intervals"+
	" along the wall to light the hallway."
	);
	set_smell("default","The faint scent of oranges is in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching off to the east"+
	" and north. It is finely woven and quite thick and sturdy. %^YELLOW%^Gold%^RESET%^"+
	" is the primary color of the rug, and a few slender %^RED%^crimson%^RESET%^"+
	" stripes line the edges.",
	({"wall","walls"}) : "The walls have been covered in plaster to help keep"+
	" the heat in and the cold out. They have been painted over in a %^BOLD%^%^RED%^light"+
	" red%^RESET%^ shade. Extravagent tapestries cover most of the walls"+
	" with oil lamps positioned inbetween them.",
	"floor" : "The floor is covered in a large rug.",
	"ceiling" : "The ceiling is smooth and rather unremarkable.",
	({"lamp","lamps","oil lamp","oil lamps","gold tinted oil lamps","gold tinted lamp"}) : "%^YELLOW%^Golden tinted oil"+
	" lamps are fixed to the walls at intervals between the tapestries. The"+
	" lamps shed light to the room, but as they burn they also give off the"+
	" pleasant smell of oranges.",
	({"tapestry","west wall","west tapestry","dragon tapestry","blue tapestry","sky blue tapestry","bronze dragon tapestry"}) : "%^BOLD%^%^CYAN%^Hung"+
	" on the west wall is an extravagent tapestry of a %^RESET%^%^ORANGE%^bronze"+
	" dragon%^BOLD%^%^CYAN%^ in flight. The dragon's wings are spread out"+
	" and his neck is arched as he blasts a bolt of %^YELLOW%^lightning%^CYAN%^"+
	" out of his mouth.",
	({"door","walnut door"}) : "To the north is a walnut door. It has the"+
	" sign of the magi engraved into the center of it.",
	]));
	set_exits(([
	"east" : ROOMS+"pal4",
	"north" : ROOMS+"mage",
	]));
	set_door("door",ROOMS+"mage","north",0);
	set_string("door","open","The walnut door opens without a squeak.");
	if(query_night() == 1) {
		set_open("door",0);
		"/d/antioch/antioch2/rooms/mage"->set_open("door",0);
	}
	else if(query_night() != 1) {
		set_open("door",1);
		"/d/antioch/antioch2/rooms/mage"->set_open("door",1);
	}
}

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
	"This is a hallway in Antioch's palace that leads to a component shop."+
	" The floor is covered in a %^YELLOW%^gold%^RESET%^ and %^RED%^crimson%^RESET%^"+
	" rug that stretches to the east and west. To the north is a doorway that"+
	" is covered by a thick %^MAGENTA%^purple%^RESET%^ curtain. On the walls"+
	" are extravagent tapestries. The north wall holds a %^BLUE%^midnight blue%^RESET%^"+
	" tapestry of a %^BLACK%^%^BOLD%^black%^RESET%^ and %^BOLD%^white%^RESET%^"+
   " tiger carefully stalking its pray. On the southern wall is a lovely"+
	" %^RED%^crimson%^RESET%^ tapestry of a %^YELLOW%^golden%^RESET%^ sunburst."+
	" In between the tapestries are %^YELLOW%^gold tinted%^RESET%^ oil lamps"+
	" that light the room."
	);
	set_smell("default","The faint scent of oranges is in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching off to the west"+
	" and east. It is finely woven and quite thick and sturdy. %^YELLOW%^Gold%^RESET%^"+
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
	({"curtain","purple curtain"}) : "%^MAGENTA%^A dark purple curtain hangs"+
	" in front of the northern doorway.",
	({"north tapestry","tiger tapestry","blue tapestry","midnight blue tapestry","northern tapestry","white tiger tapestry"}) : "%^BLUE%^A"+
	" beautiful midnight blue tapestry is hung on the northern wall. The"+
	" picture on it is of a stealthy %^BOLD%^%^BLACK%^black%^RESET%^%^BLUE%^"+
   " and %^BOLD%^%^WHITE%^white%^RESET%^%^BLUE%^ tiger carefully stalking"+
	" its prey.",
	({"southern tapestry","south tapestry","sunburst tapestry","crimson tapestry"}) : "%^RED%^The"+
	" lovely crimson tapestry is hung on the southern wall. Most of it is"+
	" covered in an incredibly extravagent %^YELLOW%^golden%^RESET%^%^RED%^"+
	" sunburst.",
	]));
	set_exits(([
	"east" : ROOMS+"pal1",
	"west" : ROOMS+"pal5",
	"north" : ROOMS+"guard1",
	]));
	set_pre_exit_functions(({"north"}),({"go_north"}));
}

int go_north()
{
	write("You brush aside the curtain as you move to the north.");
	return 1;
}

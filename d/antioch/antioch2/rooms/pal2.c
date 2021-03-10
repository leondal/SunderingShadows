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
	"This is a hallway in Antioch's palace that leads to the dining room."+
	" The floor is covered in a %^YELLOW%^gold%^RESET%^ and %^RED%^crimson%^RESET%^"+
	" rug that stretches to the edges of the doorway. The eastern door to"+
	" the dining room is made of thick mahogany wood. It is elegantly outlined"+
	" with holly leaves engraved into the edges of the door. To the north is"+
	" another doorway that is covered by a thick %^MAGENTA%^purple%^RESET%^"+
	" curtain. On the walls are extravagent tapestries. On the north wall is"+
	" a lovely %^GREEN%^green%^RESET%^ tapestry with a lovely %^BOLD%^%^RED%^red"+
	" rose%^RESET%^ that has just begun to bloom. On the south wall is a"+
	" beautiful %^BOLD%^%^GREEN%^emerald%^RESET%^ tapestry of a rushing"+
	" %^BOLD%^%^BLUE%^waterfall%^RESET%^ pouring down into a lake. %^YELLOW%^Gold"+
	" tinted%^RESET%^ oil lamps have been placed on either side of the tapestries"+
	" to light the room."
	);
	set_smell("default","The faint scent of oranges is in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching off to the west"+
	" and coming to a stop in front of the eastern door. It is finely woven"+
	" and quite thick and sturdy. %^YELLOW%^Gold%^RESET%^ is the primary color"+
	" of the rug, and a few slender %^RED%^crimson%^RESET%^ stripes line the"+
	" edges.",
	({"wall","walls"}) : "The walls have been covered in plaster to help keep"+
	" the heat in and the cold out. They have been painted over in a %^BOLD%^%^RED%^light"+
	" red%^RESET%^ shade. Extravagent tapestries cover most of the walls"+
	" with oil lamps positioned inbetween them.",
	"floor" : "The floor is covered in a large rug.",
	"ceiling" : "The ceiling is smooth and rather unremarkable.",
	({"lamp","lamps","oil lamp","oil lamps","gold tinted oil lamps","gold tinted lamps"}) : "%^YELLOW%^Golden tinted oil"+
	" lamps are fixed to the walls at intervals between the tapestries. The"+
	" lamps shed light to the room, but as they burn they also give off the"+
	" pleasant smell of oranges.",
	({"north tapestry","north wall","rose tapestry","green tapestry","tapestry 1","first tapestry","northern wall",}) : "%^GREEN%^This magnificent tapestry"+
	" is hung on the northern wall and is made of fine green silk. Carefully"+
	" sewn onto its surface is a delicate %^BOLD%^%^RED%^red rose%^RESET%^%^GREEN%^"+
	" that has just begun to bloom.",
	({"south tapestry","south wall","waterfall tapestry","emerald tapestry","tapestry 2","second tapestry","southern wall","waterfall tapestry","waterfall"}) : "%^BOLD%^%^GREEN%^The"+
	" emerald tapestry is hung on the southern wall. In the center of the"+
	" it is a refreshing %^BLUE%^waterfall%^GREEN%^ that splashes down into"+
	" a cool lake.",
	({"door","mahogany door","east door"}) : "The mahogany door fits perfectly"+
	" into an arched doorway on the eastern wall. Its edges are delicately"+
	" engraved with holly leaves.",
	({"curtain","purple curtain"}) : "%^MAGENTA%^A dark purple curtain hangs"+
	" in front of the northern doorway.",
	]));
	set_exits(([
	"west" : ROOMS+"pal1",
	"north" : ROOMS+"guard2",
	"east" : ROOMS+"pal3",
	]));
	set_door("door",ROOMS+"pal3","east",0);
	set_string("door","open","The mahogany door swings open easily.");
	set_pre_exit_functions(({"north"}),({"go_north"}));
}

int go_north()
{
	write("You brush aside the curtain as you move to the north.");
	return 1;
}

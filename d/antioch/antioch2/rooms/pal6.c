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
	"This is a hallway in Antioch's palace that leads to the throne room."+
	" The floor is covered in a %^YELLOW%^gold%^RESET%^ and %^RED%^crimson%^RESET%^"+
	" rug that stretches to the north and south. Up ahead you can see a"+
	" grand stair case that leads up to the second floor of the palace. On"+
	" the western wall you see an extravagent tapestry of a young maiden."+
	" Across from it on the eastern wall is a tapestry of a fortress in the"+
	" clouds. On either side of the tapestries are %^YELLOW%^gold tinted%^RESET%^"+
	" oil lamps that shed light on the hallway."
	);
	set_smell("default","The faint scent of oranges is in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	"rug" : "A large rug covers the entire floor, stretching off to the north"+
	" and south. It is finely woven and quite thick and sturdy. %^YELLOW%^Gold%^RESET%^"+
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
	({"west wall","western wall","west tapestry","first tapestry","tapestry 1","tapestry of a young maiden","maid tapestry","young maid tapestry","bird maiden","young maiden","young maid","bird maiden tapestry"}) : "%^CYAN%^Set"+
	" on an aquamarine background the tapestry of a young maiden hangs on the"+
	" west wall. The girl is very beautiful, she stands tall and proud in a"+
	" %^BOLD%^%^WHITE%^white gown%^RESET%^%^CYAN%^ that is drawn in at the"+
	" waist with a %^YELLOW%^golden%^RESET%^%^CYAN%^ belt. A %^BOLD%^%^WHITE%^white feather%^RESET%^%^CYAN%^"+
	" shawl is draped over her shoulders, almost giving her the appearance"+
	" of wings. Beautiful locks of %^YELLOW%^honey colored%^RESET%^%^CYAN%^"+
	" hair spill over her shoulders. Her head is tilted slightly and her"+
	" %^BOLD%^%^BLUE%^sapphire%^RESET%^%^CYAN%^ eyes seem to be staring at"+
	" you. A slight smile tugs at the corners of her %^BOLD%^%^RED%^ruby red%^RESET%^%^CYAN%^"+
	" lips.",
	({"east wall","eastern wall","east tapestry","second tapestry","tapestry 2","castle in the clouds","fortress tapestry","fortress in the clouds","fortress","cloud tapestry"}) : "%^BOLD%^%^CYAN%^On the eastern wall"+
	" hangs a tapestry of a mythical fortress in the clouds. It is set on a"+
	" background of blue silk and has several %^WHITE%^white clouds%^CYAN%^"+
	" about the picture. The fortress itself seems to be floating on a platform"+
	" of clouds. The fortress is made of wood and looks sturdy as well as"+
	" easily defendable. It is the Crown of All Feathers, the mythical"+
	" castle in the clouds where the bird maidens are trained.",
	]));
	set_exits(([
	"south" : ROOMS+"pal1",
	"north" : ROOMS+"pal7",
   "east" : "/d/antioch/cguilds/paladin/hall1",
	]));
}
